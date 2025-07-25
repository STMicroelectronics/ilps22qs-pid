/**
  ******************************************************************************
  * @file    ilps22qs_reg.h
  * @author  Sensors Software Solution Team
  * @brief   This file contains all the functions prototypes for the
  *          ilps22qs_reg.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ILPS22QS_REGS_H
#define ILPS22QS_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <math.h>

/** @addtogroup ILPS22QS
  * @{
  *
  */

/** @defgroup  Endianness definitions
  * @{
  *
  */

#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__

#define DRV_LITTLE_ENDIAN 1234
#define DRV_BIG_ENDIAN    4321

/** if _BYTE_ORDER is not defined, choose the endianness of your architecture
  * by uncommenting the define which fits your platform endianness
  */
//#define DRV_BYTE_ORDER    DRV_BIG_ENDIAN
#define DRV_BYTE_ORDER    DRV_LITTLE_ENDIAN

#else /* defined __BYTE_ORDER__ */

#define DRV_LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
#define DRV_BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#define DRV_BYTE_ORDER     __BYTE_ORDER__

#endif /* __BYTE_ORDER__*/
#endif /* DRV_BYTE_ORDER */

/**
  * @}
  *
  */

/** @defgroup STMicroelectronics sensors common types
  * @{
  *
  */

#ifndef MEMS_SHARED_TYPES
#define MEMS_SHARED_TYPES

typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bit0       : 1;
  uint8_t bit1       : 1;
  uint8_t bit2       : 1;
  uint8_t bit3       : 1;
  uint8_t bit4       : 1;
  uint8_t bit5       : 1;
  uint8_t bit6       : 1;
  uint8_t bit7       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bit7       : 1;
  uint8_t bit6       : 1;
  uint8_t bit5       : 1;
  uint8_t bit4       : 1;
  uint8_t bit3       : 1;
  uint8_t bit2       : 1;
  uint8_t bit1       : 1;
  uint8_t bit0       : 1;
#endif /* DRV_BYTE_ORDER */
} bitwise_t;

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)

/** @addtogroup  Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, const uint8_t *, uint16_t);
typedef int32_t (*stmdev_read_ptr)(void *, uint8_t, uint8_t *, uint16_t);
typedef void (*stmdev_mdelay_ptr)(uint32_t millisec);

typedef struct
{
  /** Component mandatory fields **/
  stmdev_write_ptr  write_reg;
  stmdev_read_ptr   read_reg;
  /** Component optional fields **/
  stmdev_mdelay_ptr   mdelay;
  /** Customizable optional pointer **/
  void *handle;

  /** private data **/
  void *priv_data;
} stmdev_ctx_t;

/**
  * @}
  *
  */

#endif /* MEMS_SHARED_TYPES */

#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** @defgroup    Generic address-data structure definition
  * @brief       This structure is useful to load a predefined configuration
  *              of a sensor.
  *              You can create a sensor configuration by your own or using
  *              Unico / Unicleo tools available on STMicroelectronics
  *              web site.
  *
  * @{
  *
  */

typedef struct
{
  uint8_t address;
  uint8_t data;
} ucf_line_t;

/**
  * @}
  *
  */

#endif /* MEMS_UCF_SHARED_TYPES */

/**
  * @}
  *
  */

/** @defgroup ILPS22QS_Infos
  * @{
  *
  */

/** I2C Device Address 8 bit format **/
#define ILPS22QS_I2C_ADD                 0xB9U

/** Device Identification (Who am I) **/
#define ILPS22QS_ID                      0xB4U

/**
  * @}
  *
  */

#define ILPS22QS_INTERRUPT_CFG           0x0BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t phe              : 1;
  uint8_t ple              : 1;
  uint8_t lir              : 1;
  uint8_t not_used_01      : 1;
  uint8_t reset_az         : 1;
  uint8_t autozero         : 1;
  uint8_t reset_arp        : 1;
  uint8_t autorefp         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t autorefp         : 1;
  uint8_t reset_arp        : 1;
  uint8_t autozero         : 1;
  uint8_t reset_az         : 1;
  uint8_t not_used_01      : 1;
  uint8_t lir              : 1;
  uint8_t ple              : 1;
  uint8_t phe              : 1;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_interrupt_cfg_t;

#define ILPS22QS_THS_P_L                 0x0CU
typedef struct
{
  uint8_t ths              : 8;
} ilps22qs_ths_p_l_t;

#define ILPS22QS_THS_P_H                 0x0DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ths              : 7;
  uint8_t not_used_01      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01      : 1;
  uint8_t ths              : 7;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_ths_p_h_t;

#define ILPS22QS_IF_CTRL                 0x0EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_01      : 1;
  uint8_t cs_pu_dis        : 1;
  uint8_t not_used_02      : 2;
  uint8_t sda_pu_en        : 1;
  uint8_t en_spi_read      : 1;
  uint8_t i2c_i3c_dis      : 1;
  uint8_t not_used_03      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_03      : 1;
  uint8_t i2c_i3c_dis      : 1;
  uint8_t en_spi_read      : 1;
  uint8_t sda_pu_en        : 1;
  uint8_t not_used_02      : 2;
  uint8_t cs_pu_dis        : 1;
  uint8_t not_used_01      : 1;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_if_ctrl_t;

#define ILPS22QS_WHO_AM_I                0x0FU
#define ILPS22QS_CTRL_REG1               0x10U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t avg              : 3;
  uint8_t odr              : 4;
  uint8_t not_used_01      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01      : 1;
  uint8_t odr              : 4;
  uint8_t avg              : 3;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_ctrl_reg1_t;

#define ILPS22QS_CTRL_REG2               0x11U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t oneshot          : 1;
  uint8_t not_used_01      : 1;
  uint8_t swreset          : 1;
  uint8_t bdu              : 1;
  uint8_t en_lpfp          : 1;
  uint8_t lfpf_cfg         : 1;
  uint8_t fs_mode          : 1;
  uint8_t boot             : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t boot             : 1;
  uint8_t fs_mode          : 1;
  uint8_t lfpf_cfg         : 1;
  uint8_t en_lpfp          : 1;
  uint8_t bdu              : 1;
  uint8_t swreset          : 1;
  uint8_t not_used_01      : 1;
  uint8_t oneshot          : 1;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_ctrl_reg2_t;

#define ILPS22QS_CTRL_REG3               0x12U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t if_add_inc       : 1;
  uint8_t not_used_01      : 4;
  uint8_t ah_qvar_p_auto_en: 1;
  uint8_t not_used_02      : 1;
  uint8_t ah_qvar_en       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ah_qvar_en       : 1;
  uint8_t not_used_02      : 1;
  uint8_t ah_qvar_p_auto_en: 1;
  uint8_t not_used_01      : 4;
  uint8_t if_add_inc       : 1;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_ctrl_reg3_t;

#define ILPS22QS_FIFO_CTRL               0x14U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t f_mode           : 2;
  uint8_t trig_modes       : 1;
  uint8_t stop_on_wtm      : 1;
  uint8_t ah_qvar_p_fifo_en: 1;
  uint8_t not_used_01      : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01      : 3;
  uint8_t ah_qvar_p_fifo_en: 1;
  uint8_t stop_on_wtm      : 1;
  uint8_t trig_modes       : 1;
  uint8_t f_mode           : 2;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_fifo_ctrl_t;

#define ILPS22QS_FIFO_WTM                0x15U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t wtm              : 7;
  uint8_t not_used_01      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01      : 1;
  uint8_t wtm              : 7;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_fifo_wtm_t;

#define ILPS22QS_REF_P_L                 0x16U
typedef struct
{
  uint8_t refp             : 8;
} ilps22qs_ref_p_l_t;

#define ILPS22QS_REF_P_H                 0x17U
typedef struct
{
  uint8_t refp             : 8;
} ilps22qs_ref_p_h_t;

#define ILPS22QS_I3C_IF_CTRL             0x19U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_02      : 5;
  uint8_t asf_on           : 1;
  uint8_t not_used_01      : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01      : 2;
  uint8_t asf_on           : 1;
  uint8_t not_used_02      : 5;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_i3c_if_ctrl_t;

#define ILPS22QS_RPDS_L                  0x1AU
#define ILPS22QS_RPDS_H                  0x1BU
#define ILPS22QS_INT_SOURCE              0x24U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ph               : 1;
  uint8_t pl               : 1;
  uint8_t ia               : 1;
  uint8_t not_used_01      : 4;
  uint8_t boot_on          : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t boot_on          : 1;
  uint8_t not_used_01      : 4;
  uint8_t ia               : 1;
  uint8_t pl               : 1;
  uint8_t ph               : 1;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_int_source_t;

#define ILPS22QS_FIFO_STATUS1            0x25U
typedef struct
{
  uint8_t fss              : 8;
} ilps22qs_fifo_status1_t;

#define ILPS22QS_FIFO_STATUS2            0x26U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_01      : 5;
  uint8_t fifo_full_ia     : 1;
  uint8_t fifo_ovr_ia      : 1;
  uint8_t fifo_wtm_ia      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_wtm_ia      : 1;
  uint8_t fifo_ovr_ia      : 1;
  uint8_t fifo_full_ia     : 1;
  uint8_t not_used_01      : 5;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_fifo_status2_t;

#define ILPS22QS_STATUS                  0x27U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t p_da             : 1;
  uint8_t t_da             : 1;
  uint8_t not_used_01      : 2;
  uint8_t p_or             : 1;
  uint8_t t_or             : 1;
  uint8_t not_used_02      : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_02      : 2;
  uint8_t t_or             : 1;
  uint8_t p_or             : 1;
  uint8_t not_used_01      : 2;
  uint8_t t_da             : 1;
  uint8_t p_da             : 1;
#endif /* DRV_BYTE_ORDER */
} ilps22qs_status_t;

#define ILPS22QS_PRESS_OUT_XL            0x28U
#define ILPS22QS_PRESS_OUT_L             0x29U
#define ILPS22QS_PRESS_OUT_H             0x2AU
#define ILPS22QS_TEMP_OUT_L              0x2BU
#define ILPS22QS_TEMP_OUT_H              0x2CU
#define ILPS22QS_ANALOGIC_HUB_DISABLE    0x5FU
#define ILPS22QS_FIFO_DATA_OUT_PRESS_XL  0x78U
#define ILPS22QS_FIFO_DATA_OUT_PRESS_L   0x79U
#define ILPS22QS_FIFO_DATA_OUT_PRESS_H   0x7AU

/**
  * @defgroup ILPS22QS_Register_Union
  * @brief    This union group all the registers that has a bitfield
  *           description.
  *           This union is useful but not need by the driver.
  *
  *           REMOVING this union you are compliant with:
  *           MISRA-C 2012 [Rule 19.2] -> " Union are not allowed "
  *
  * @{
  *
  */

typedef union
{
  ilps22qs_interrupt_cfg_t    interrupt_cfg;
  ilps22qs_ths_p_l_t          ths_p_l;
  ilps22qs_ths_p_h_t          ths_p_h;
  ilps22qs_if_ctrl_t          if_ctrl;
  ilps22qs_ctrl_reg1_t        ctrl_reg1;
  ilps22qs_ctrl_reg2_t        ctrl_reg2;
  ilps22qs_ctrl_reg3_t        ctrl_reg3;
  ilps22qs_fifo_ctrl_t        fifo_ctrl;
  ilps22qs_fifo_wtm_t         fifo_wtm;
  ilps22qs_ref_p_l_t          ref_p_l;
  ilps22qs_ref_p_h_t          ref_p_h;
  ilps22qs_i3c_if_ctrl_t      i3c_if_ctrl;
  ilps22qs_int_source_t       int_source;
  ilps22qs_fifo_status1_t     fifo_status1;
  ilps22qs_fifo_status2_t     fifo_status2;
  ilps22qs_status_t           status;
  bitwise_t                  bitwise;
  uint8_t                    byte;
} ilps22qs_reg_t;

#ifndef __weak
#define __weak __attribute__((weak))
#endif /* __weak */

/*
 * These are the basic platform dependent I/O routines to read
 * and write device registers connected on a standard bus.
 * The driver keeps offering a default implementation based on function
 * pointers to read/write routines for backward compatibility.
 * The __weak directive allows the final application to overwrite
 * them with a custom implementation.
 */

int32_t ilps22qs_read_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                          uint8_t *data, uint16_t len);
int32_t ilps22qs_write_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                           uint8_t *data, uint16_t len);

extern float_t ilps22qs_from_fs1260_to_hPa(int32_t lsb);
extern float_t ilps22qs_from_fs4000_to_hPa(int32_t lsb);
extern float_t ilps22qs_from_lsb_to_celsius(int16_t lsb);
extern float_t ilps22qs_from_lsb_to_mv(int32_t lsb);

typedef struct
{
  uint8_t whoami;
} ilps22qs_id_t;
int32_t ilps22qs_id_get(const stmdev_ctx_t *ctx, ilps22qs_id_t *val);

typedef enum
{
  ILPS22QS_SEL_BY_HW      = 0x00, /* bus mode select by HW (SPI 3W disable) */
  ILPS22QS_SPI_3W         = 0x03, /* Only SPI: SDO / SDI share the same pin */
} ilps22qs_interface_t;

typedef enum
{
  ILPS22QS_FILTER_AUTO      = 0x00, /* Disable anti-spike filters */
  ILPS22QS_FILTER_ALWAYS_ON = 0x01, /* Enable anti-spike filters */
} ilps22qs_filter_t;

typedef struct
{
  ilps22qs_interface_t interface;
  ilps22qs_filter_t filter;
} ilps22qs_bus_mode_t;
int32_t ilps22qs_bus_mode_set(const stmdev_ctx_t *ctx, ilps22qs_bus_mode_t *val);
int32_t ilps22qs_bus_mode_get(const stmdev_ctx_t *ctx, ilps22qs_bus_mode_t *val);

typedef enum
{
  ILPS22QS_DRV_RDY = 0x00, /* Initialize the device for driver usage */
  ILPS22QS_BOOT    = 0x01, /* Restore calib. param. ( it takes 10ms ) */
  ILPS22QS_RESET   = 0x02, /* Reset configuration registers */
} ilps22qs_init_t;
int32_t ilps22qs_init_set(const stmdev_ctx_t *ctx, ilps22qs_init_t val);

typedef struct
{
  uint8_t sw_reset  : 1; /* Restoring configuration registers. */
  uint8_t boot      : 1; /* Restoring calibration parameters. */
  uint8_t drdy_pres : 1; /* Pressure data ready. */
  uint8_t drdy_temp : 1; /* Temperature data ready. */
  uint8_t ovr_pres  : 1; /* Pressure data overrun. */
  uint8_t ovr_temp  : 1; /* Temperature data overrun. */
  uint8_t end_meas  : 1; /* Single measurement is finished. */
  uint8_t ref_done  : 1; /* Auto-Zero value is set. */
} ilps22qs_stat_t;
int32_t ilps22qs_status_get(const stmdev_ctx_t *ctx, ilps22qs_stat_t *val);

typedef struct
{
  uint8_t sda_pull_up : 1; /* 1 = pull-up enabled */
  uint8_t cs_pull_up  : 1; /* 1 = pull-up enabled */
} ilps22qs_pin_conf_t;
int32_t ilps22qs_pin_conf_set(const stmdev_ctx_t *ctx, ilps22qs_pin_conf_t *val);
int32_t ilps22qs_pin_conf_get(const stmdev_ctx_t *ctx, ilps22qs_pin_conf_t *val);

typedef struct
{
  uint8_t drdy_pres   :  1; /* Pressure data ready */
  uint8_t drdy_temp   :  1; /* Temperature data ready */
  uint8_t over_pres   :  1; /* Over pressure event */
  uint8_t under_pres  :  1; /* Under pressure event */
  uint8_t thrsld_pres :  1; /* Over/Under pressure event */
  uint8_t fifo_full   :  1; /* FIFO full */
  uint8_t fifo_ovr    :  1; /* FIFO overrun */
  uint8_t fifo_th     :  1; /* FIFO threshold reached */
} ilps22qs_all_sources_t;
int32_t ilps22qs_all_sources_get(const stmdev_ctx_t *ctx, ilps22qs_all_sources_t *val);

typedef enum
{
  ILPS22QS_1260hPa = 0x00,
  ILPS22QS_4060hPa = 0x01,
} ilps22qs_fs_t;

typedef enum
{
  ILPS22QS_ONE_SHOT = 0x00, /* Device in power down till software trigger */
  ILPS22QS_1Hz      = 0x01,
  ILPS22QS_4Hz      = 0x02,
  ILPS22QS_10Hz     = 0x03,
  ILPS22QS_25Hz     = 0x04,
  ILPS22QS_50Hz     = 0x05,
  ILPS22QS_75Hz     = 0x06,
  ILPS22QS_100Hz    = 0x07,
  ILPS22QS_200Hz    = 0x08,
} ilps22qs_odr_t;

typedef enum
{
  ILPS22QS_4_AVG   = 0,
  ILPS22QS_8_AVG   = 1,
  ILPS22QS_16_AVG  = 2,
  ILPS22QS_32_AVG  = 3,
  ILPS22QS_64_AVG  = 4,
  ILPS22QS_128_AVG = 5,
  ILPS22QS_256_AVG = 6,
  ILPS22QS_512_AVG = 7,
} ilps22qs_avg_t;

typedef enum
{
  ILPS22QS_LPF_DISABLE   = 0,
  ILPS22QS_LPF_ODR_DIV_4 = 1,
  ILPS22QS_LPF_ODR_DIV_9 = 3,
} ilps22qs_lpf_t;

typedef struct
{
  uint8_t interleaved_mode;
  ilps22qs_fs_t fs;
  ilps22qs_odr_t odr;
  ilps22qs_avg_t avg;
  ilps22qs_lpf_t lpf;
} ilps22qs_md_t;
int32_t ilps22qs_mode_set(const stmdev_ctx_t *ctx, ilps22qs_md_t *val);
int32_t ilps22qs_mode_get(const stmdev_ctx_t *ctx, ilps22qs_md_t *val);

int32_t ilps22qs_trigger_sw(const stmdev_ctx_t *ctx, ilps22qs_md_t *md);

typedef struct
{
  struct
  {
    float_t hpa;
    int32_t raw; /* 32 bit signed-left algned  format left  */
  } pressure;
  struct
  {
    float_t deg_c;
    int16_t raw;
  } heat;
  struct
  {
    int32_t lsb; /* 24 bit properly right aligned */
  } ah_qvar;
} ilps22qs_data_t;
int32_t ilps22qs_data_get(const stmdev_ctx_t *ctx, ilps22qs_md_t *md,
                          ilps22qs_data_t *data);

int32_t ilps22qs_pressure_raw_get(const stmdev_ctx_t *ctx, uint32_t *buff);
int32_t ilps22qs_temperature_raw_get(const stmdev_ctx_t *ctx, int16_t *buff);

typedef struct
{
  float_t mv; /* value converted in mV */
  int32_t lsb; /* 24 bit properly right aligned */
  int32_t raw; /* 32 bit signed-left algned  format left  */
} ilps22qs_ah_qvar_data_t;
int32_t ilps22qs_ah_qvar_data_get(const stmdev_ctx_t *ctx,
                                  ilps22qs_ah_qvar_data_t *data);

typedef enum
{
  ILPS22QS_BYPASS           = 0,
  ILPS22QS_FIFO             = 1,
  ILPS22QS_STREAM           = 2,
  ILPS22QS_STREAM_TO_FIFO   = 7, /* Dynamic-Stream, FIFO on Trigger */
  ILPS22QS_BYPASS_TO_STREAM = 6, /* Bypass, Dynamic-Stream on Trigger */
  ILPS22QS_BYPASS_TO_FIFO   = 5, /* Bypass, FIFO on Trigger */
} ilps22qs_operation_t;

typedef struct
{
  ilps22qs_operation_t operation;
  uint8_t watermark : 7; /* (0 disable) max 128.*/
} ilps22qs_fifo_md_t;
int32_t ilps22qs_fifo_mode_set(const stmdev_ctx_t *ctx, ilps22qs_fifo_md_t *val);
int32_t ilps22qs_fifo_mode_get(const stmdev_ctx_t *ctx, ilps22qs_fifo_md_t *val);

int32_t ilps22qs_fifo_level_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  float_t hpa;
  int32_t lsb; /* 24 bit properly right aligned */
  int32_t raw;
} ilps22qs_fifo_data_t;
int32_t ilps22qs_fifo_data_get(const stmdev_ctx_t *ctx, uint8_t samp,
                               ilps22qs_md_t *md, ilps22qs_fifo_data_t *data);

typedef struct
{
  uint8_t int_latched  : 1; /* int events are: int on threshold, FIFO */
} ilps22qs_int_mode_t;
int32_t ilps22qs_interrupt_mode_set(const stmdev_ctx_t *ctx, ilps22qs_int_mode_t *val);
int32_t ilps22qs_interrupt_mode_get(const stmdev_ctx_t *ctx, ilps22qs_int_mode_t *val);

int32_t ilps22qs_ah_qvar_disable(const stmdev_ctx_t *ctx);
int32_t ilps22qs_ah_qvar_en_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t ilps22qs_ah_qvar_en_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  uint16_t threshold;   /* Threshold in hPa * 16 (@1260hPa)
                         * Threshold in hPa * 8  (@4060hPa)
                         */
  uint8_t over_th  : 1; /* Pressure data over threshold event */
  uint8_t under_th : 1; /* Pressure data under threshold event */
} ilps22qs_int_th_md_t;
int32_t ilps22qs_int_on_threshold_mode_set(const stmdev_ctx_t *ctx,
                                           ilps22qs_int_th_md_t *val);
int32_t ilps22qs_int_on_threshold_mode_get(const stmdev_ctx_t *ctx,
                                           ilps22qs_int_th_md_t *val);

typedef enum
{
  ILPS22QS_OUT_AND_INTERRUPT = 0,
  ILPS22QS_ONLY_INTERRUPT    = 1,
  ILPS22QS_RST_REFS          = 2,
} ilps22qs_apply_ref_t;

typedef struct
{
  ilps22qs_apply_ref_t apply_ref;
  uint8_t get_ref : 1; /* Use current pressure value as reference */
} ilps22qs_ref_md_t;
int32_t ilps22qs_reference_mode_set(const stmdev_ctx_t *ctx,
                                    ilps22qs_ref_md_t *val);
int32_t ilps22qs_reference_mode_get(const stmdev_ctx_t *ctx,
                                    ilps22qs_ref_md_t *val);

int32_t ilps22qs_opc_set(const stmdev_ctx_t *ctx, int16_t val);
int32_t ilps22qs_opc_get(const stmdev_ctx_t *ctx, int16_t *val);

/**
  *@}
  *
  */

#ifdef __cplusplus
}
#endif

#endif /* ILPS22QS_REGS_H */
