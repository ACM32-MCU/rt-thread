/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date         Author        Notes
 * 2022-7-4     AisinoChip    first add to bsp
 */

#include "board.h"
#include <rtdevice.h>

#if defined(RT_USING_HWCRYPTO)

void delay(uint32_t cnt)
{
    while(cnt--);
}

struct acm32_hwcrypto_device
{
    struct rt_hwcrypto_device dev;
    struct rt_mutex mutex;
};

#if defined(RT_HWCRYPTO_USING_CRC) && defined(BSP_USING_CRC)
static rt_uint32_t _crc_update(struct hwcrypto_crc *ctx,
        const rt_uint8_t *in, rt_size_t length)
{

    CRC_HandleTypeDef   *hcrc = ctx->parent.contex;
    hcrc->CRC_Data_Buff = (uint8_t*)in;
    hcrc->CRC_Data_Len = length;
    hcrc->Instance = CRC;

    hcrc->Init.PolyRev = CRC_POLY_REV_EN;
    hcrc->Init.OutxorRev = CRC_OUTXOR_REV_EN;
    hcrc->Init.InitRev = CRC_INIT_REV_EN;
    hcrc->Init.RsltRev = ctx->crc_cfg.flags&CRC_FLAG_REFOUT ? CRC_RSLT_REV_DIS : CRC_RSLT_REV_EN;
    hcrc->Init.DataRev = ctx->crc_cfg.flags&CRC_FLAG_REFIN ? CRC_DATA_REV_DISABLE : CRC_DATA_REV_BY_BYTE;

    hcrc->Init.DataLen = CRC_DATA_LEN_1B;

    hcrc->Init.OutXorData = ctx->crc_cfg.xorout;
    hcrc->Init.InitData = ctx->crc_cfg.last_val;
    hcrc->Init.PolyData = ctx->crc_cfg.poly;
    switch(ctx->crc_cfg.width)
    {
        case 7:
            hcrc->Init.PolyLen = CRC_POLTY_LEN_7;
            break;
        case 8:
            hcrc->Init.PolyLen = CRC_POLTY_LEN_8;
            break;
        case 16:
            hcrc->Init.PolyLen = CRC_POLTY_LEN_16;
            break;
        case 32:
            hcrc->Init.PolyLen = CRC_POLTY_LEN_32;
            break;
        default:
            return 0;
    }

    return HAL_CRC_Calculate(hcrc);
}

static const struct hwcrypto_crc_ops crc_ops =
{
    .update = _crc_update,
};
#endif /* RT_HWCRYPTO_USING_CRC && BSP_USING_CRC */

#if defined(RT_HWCRYPTO_USING_RNG) && defined(BSP_USING_HRNG)
static rt_uint32_t _rng_rand(struct hwcrypto_rng *ctx)
{
    return HAL_HRNG_GetHrng_32();
}

static const struct hwcrypto_rng_ops rng_ops =
{
    .update = _rng_rand,
};
#endif /* RT_HWCRYPTO_USING_RNG && BSP_USING_HRNG */

#if defined(RT_HWCRYPTO_USING_AES) && defined(BSP_USING_AES)
static rt_err_t _symmetric_crypt(struct hwcrypto_symmetric *symmetric_ctx,
                      struct hwcrypto_symmetric_info *symmetric_info)
{
    struct rt_hwcrypto_ctx parent;                      /**< Inheritance from hardware crypto context */
    rt_uint32_t flags;                                  /**< key or iv or ivoff has been changed. The flag will be set up */
    rt_int32_t iv_len;                                  /**< initialization vector effective length */
    rt_int32_t iv_off;                                  /**< The offset in IV */
    rt_uint8_t iv[RT_HWCRYPTO_IV_MAX_SIZE];             /**< The initialization vector */
    rt_uint8_t key[RT_HWCRYPTO_KEYBIT_MAX_SIZE >> 3];   /**< The crypto key */
    rt_int32_t key_bitlen;                              /**< The crypto key bit length */

    uint8_t mode;
    switch(symmetric_ctx->parent.type)
    {
        case HWCRYPTO_TYPE_AES_ECB:
            if(symmetric_ctx->flags&SYMMTRIC_MODIFY_KEY)
            {
                HAL_AES_SetKey_U8(symmetric_ctx->key, (symmetric_ctx->key_bitlen-128)>>6, AES_SWAP_ENABLE);
            }

            HAL_AES_Crypt_U8(
                    (uint8_t*)symmetric_info->in,
                    symmetric_info->out,
                    symmetric_info->length>>3,
                    symmetric_info->mode == HWCRYPTO_MODE_ENCRYPT ? AES_ENCRYPTION : AES_DECRYPTION,
                    AES_ECB_MODE,
                    &symmetric_ctx->iv[symmetric_ctx->iv_off],
                    AES_NORMAL_MODE);
            break;
        case HWCRYPTO_TYPE_AES_CBC:
            if(symmetric_ctx->flags&SYMMTRIC_MODIFY_KEY)
            {
                HAL_AES_SetKey_U8(symmetric_ctx->key, (symmetric_ctx->key_bitlen-128)>>6, AES_SWAP_ENABLE);
            }

            HAL_AES_Crypt_U8(
                    (uint8_t*)symmetric_info->in,
                    symmetric_info->out,
                    symmetric_info->length>>3,
                    symmetric_info->mode == HWCRYPTO_MODE_ENCRYPT ? AES_ENCRYPTION : AES_DECRYPTION,
                    AES_CBC_MODE,
                    &symmetric_ctx->iv[symmetric_ctx->iv_off],
                    AES_NORMAL_MODE);
            break;
        default:
            return -RT_EINVAL;
    }


    return RT_EOK;
}

static const struct hwcrypto_symmetric_ops aes_ops =
{
    .crypt = _symmetric_crypt
};
#endif /* RT_HWCRYPTO_USING_AES && BSP_USING_AES */

#if defined(RT_HWCRYPTO_USING_SHA1) && defined(BSP_USING_SHA1)

static rt_err_t _sha1_update(struct hwcrypto_hash *hash_ctx,
        const rt_uint8_t *in, rt_size_t length)
{
    HAL_SHA1_Update((SHA1_CTX*)hash_ctx->parent.contex, (uint8_t*)in, length);
    return RT_EOK;
}

static rt_err_t _sha1_finish(struct hwcrypto_hash *hash_ctx,
        rt_uint8_t *out, rt_size_t length)
{
    if(length < 20)
    {
        return -RT_EINVAL;
    }
    HAL_SHA1_Final(out, (SHA1_CTX*)hash_ctx->parent.contex);
    return RT_EOK;
}

static const struct hwcrypto_hash_ops sha1_ops =
{
    .update = _sha1_update,
    .finish = _sha1_finish,
};
#endif /* defined(RT_HWCRYPTO_USING_SHA1) && defined(BSP_USING_SHA1) */
#if defined(RT_HWCRYPTO_USING_SHA2_256) && defined(BSP_USING_SHA256)

static rt_err_t _sha256_update(struct hwcrypto_hash *hash_ctx,
        const rt_uint8_t *in, rt_size_t length)
{
    HAL_SHA256_Update((SHA256_CTX*)hash_ctx->parent.contex, (uint8_t*)in, length);
    return RT_EOK;
}

static rt_err_t _sha256_finish(struct hwcrypto_hash *hash_ctx,
        rt_uint8_t *out, rt_size_t length)
{
    if(length < 32)
    {
        return -RT_EINVAL;
    }
    HAL_SHA256_Final(out, (SHA256_CTX*)hash_ctx->parent.contex);
    return RT_EOK;
}
static const struct hwcrypto_hash_ops sha256_ops =
{
    .update = _sha256_update,
    .finish = _sha256_finish,
};
#endif /* defined(RT_HWCRYPTO_USING_SHA2_256) && defined(BSP_USING_SHA256) */

static rt_err_t _crypto_create(struct rt_hwcrypto_ctx *ctx)
{
    rt_err_t res = RT_EOK;

    switch (ctx->type & (HWCRYPTO_MAIN_TYPE_MASK|HWCRYPTO_SUB_TYPE_MASK))
    {
#if defined(BSP_USING_HRNG)
    case HWCRYPTO_TYPE_RNG:
    {
        HAL_HRNG_Initial();
        ctx->contex = RT_NULL;
        ((struct hwcrypto_rng *)ctx)->ops = &rng_ops;
        break;
    }
#endif /* BSP_USING_HRNG */

#if defined(BSP_USING_CRC)
    case HWCRYPTO_TYPE_CRC:
    {
        ctx->contex = rt_malloc(sizeof(CRC_HandleTypeDef));
        if(ctx->contex == RT_NULL)
        {
            res = -RT_ENOMEM;
        }
        else
        {
            ((struct hwcrypto_crc *)ctx)->ops = &crc_ops;
        }
        break;
    }
#endif /* BSP_USING_CRC */

#if defined(BSP_USING_AES)
    case HWCRYPTO_TYPE_AES_ECB:
    case HWCRYPTO_TYPE_AES_CBC:
    {
        ctx->contex = RT_NULL;
        ((struct hwcrypto_symmetric *)ctx)->ops = &aes_ops;
        break;
    }
#endif  /* BSP_USING_AES */

#if defined(BSP_USING_SHA1)
    case HWCRYPTO_TYPE_SHA1:
    {
        ctx->contex = rt_malloc(sizeof(SHA1_CTX));
        if(ctx->contex == RT_NULL)
        {
            res = -RT_ENOMEM;
        }
        else
        {
            ((struct hwcrypto_hash *)ctx)->ops = &sha1_ops;
            HAL_SHA1_Init(ctx->contex);
        }
        break;
    }
#endif /* BSP_USING_SHA1 */

#if defined(BSP_USING_SHA256)
    case HWCRYPTO_TYPE_SHA256:
    {
        ctx->contex = rt_malloc(sizeof(SHA256_CTX));
        if(ctx->contex == RT_NULL)
        {
            res = -RT_ENOMEM;
        }
        else
        {
            ((struct hwcrypto_hash *)ctx)->ops = &sha256_ops;
            HAL_SHA256_Init(ctx->contex);
        }
        break;
    }
#endif /* BSP_USING_SHA256 */

    default:
        res = -RT_ERROR;
        break;
    }
    return res;
}

static void _crypto_destroy(struct rt_hwcrypto_ctx *ctx)
{
    switch (ctx->type & HWCRYPTO_MAIN_TYPE_MASK)
    {
#if defined(BSP_USING_HRNG)
    case HWCRYPTO_TYPE_RNG:
        break;
#endif /* BSP_USING_HRNG */

#if defined(BSP_USING_CRC)
    case HWCRYPTO_TYPE_CRC:
        rt_free(ctx->contex);
        break;
#endif /* BSP_USING_CRC */

#if defined(BSP_USING_AES)
    case HWCRYPTO_TYPE_AES:
         break;
#endif /* BSP_USING_AES */

#if defined(BSP_USING_SHA1)
    case HWCRYPTO_TYPE_SHA1:
         rt_free(ctx->contex);
         break;
#endif /* BSP_USING_SHA1 */

#if defined(BSP_USING_SHA256)
    case HWCRYPTO_TYPE_SHA256:
         rt_free(ctx->contex);
         break;
#endif /* BSP_USING_SHA256 */

    default:
        break;
    }
}

static rt_err_t _crypto_clone(struct rt_hwcrypto_ctx *des, const struct rt_hwcrypto_ctx *src)
{
    rt_err_t res = RT_EOK;

    switch (src->type & HWCRYPTO_MAIN_TYPE_MASK)
    {
#if defined(BSP_USING_HRNG)
        case HWCRYPTO_TYPE_RNG:
            break;
#endif /* BSP_USING_HRNG */

#if defined(BSP_USING_CRC)
        case HWCRYPTO_TYPE_CRC:
            if (des->contex && src->contex)
            {
                rt_memcpy(des->contex, src->contex, sizeof(CRC_HandleTypeDef));
            }
            break;
#endif /* BSP_USING_CRC */

#if defined(BSP_USING_AES)
        case HWCRYPTO_TYPE_AES:
            break;
#endif /* BSP_USING_AES */

#if defined(BSP_USING_SHA1)
        case HWCRYPTO_TYPE_SHA1:
            if (des->contex && src->contex)
            {
                rt_memcpy(des->contex, src->contex, sizeof(SHA1_CTX));
            }
            break;
#endif /* BSP_USING_SHA1 */

#if defined(BSP_USING_SHA256)
        case HWCRYPTO_TYPE_SHA256:
            if (des->contex && src->contex)
            {
                rt_memcpy(des->contex, src->contex, sizeof(SHA256_CTX));
            }
            break;
#endif /* BSP_USING_SHA256 */

        default:
            res = -RT_ERROR;
            break;
    }
    return res;
}

static void _crypto_reset(struct rt_hwcrypto_ctx *ctx)
{
    switch (ctx->type & HWCRYPTO_MAIN_TYPE_MASK)
    {
#if defined(BSP_USING_HRNG)
    case HWCRYPTO_TYPE_RNG:
        break;
#endif /* BSP_USING_HRNG */

#if defined(BSP_USING_CRC)
    case HWCRYPTO_TYPE_CRC:
        break;
#endif /* BSP_USING_CRC */

#if defined(BSP_USING_AES)
    case HWCRYPTO_TYPE_AES:
        break;
#endif /* BSP_USING_AES */

#if defined(BSP_USING_SHA1)
    case HWCRYPTO_TYPE_SHA1:
        rt_memset(ctx->contex, 0, sizeof(SHA1_CTX));
        HAL_SHA1_Init(ctx->contex);
        break;
#endif /* BSP_USING_SHA1 */

#if defined(BSP_USING_SHA256)
    case HWCRYPTO_TYPE_SHA256:
        rt_memset(ctx->contex, 0, sizeof(SHA256_CTX));
        HAL_SHA256_Init(ctx->contex);
        break;
#endif /* BSP_USING_SHA256 */

    default:
        break;
    }
}

static const struct rt_hwcrypto_ops _ops =
{
    .create = _crypto_create,
    .destroy = _crypto_destroy,
    .copy = _crypto_clone,
    .reset = _crypto_reset,
};

int rt_hw_crypto_device_init(void)
{
    static struct acm32_hwcrypto_device _crypto_dev;

#if defined(RT_HWCRYPTO_USING_CRC) && defined(BSP_USING_CRC)
#endif /* defined(RT_HWCRYPTO_USING_CRC && defined(BSP_USING_CRC) */
#if defined(RT_HWCRYPTO_USING_AES) && defined(BSP_USING_AES)
#endif /* defined(RT_HWCRYPTO_USING_AES) && defined(BSP_USING_AES) */
#if defined(RT_HWCRYPTO_USING_RNG) && defined(BSP_USING_HRNG)
#endif /* defined(RT_HWCRYPTO_USING_RNG) && defined(BSP_USING_HRNG) */
#if defined(RT_HWCRYPTO_USING_SHA1) && defined(BSP_USING_SHA1)
#endif /* defined(RT_HWCRYPTO_USING_SHA1) && defined(BSP_USING_SHA1) */
#if defined(RT_HWCRYPTO_USING_SHA2_256) && defined(BSP_USING_SHA256)
#endif /* defined(RT_HWCRYPTO_USING_SHA2_256) && defined(BSP_USING_SHA256) */

    _crypto_dev.dev.ops = &_ops;

    _crypto_dev.dev.user_data = &_crypto_dev;

    if (rt_hwcrypto_register(&_crypto_dev.dev, RT_HWCRYPTO_DEFAULT_NAME) != RT_EOK)
    {
        return -1;
    }
    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_crypto_device_init);

#endif /* RT_USING_HWCRYPTO */

