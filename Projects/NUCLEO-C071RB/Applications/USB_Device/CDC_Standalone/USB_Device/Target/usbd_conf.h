/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           USB_Device/CDC_Standalone/USB_Device/Target/usbd_conf.h
  * @author         MCD Application Team
  * @brief          Header for usbd_conf.c file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF__H__
#define __USBD_CONF__H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32c0xx.h"
#include "stm32c0xx_hal.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */


/** @defgroup USBD_CONF_Exported_Variables USBD_CONF_Exported_Variables
  * @brief Public variables.
  * @{
  */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* USER CODE END PV */
/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Defines USBD_CONF_Exported_Defines
  * @brief Defines for configuration of the Usb device.
  * @{
  */

/*---------- -----------*/
#define USBD_MAX_NUM_INTERFACES        1U
/*---------- -----------*/
#define USBD_MAX_NUM_CONFIGURATION     1U
/*---------- -----------*/
#define USBD_MAX_STR_DESC_SIZ          200U
/*---------- -----------*/
#define USBD_DEBUG_LEVEL               0U
/*---------- -----------*/
#define USBD_LPM_ENABLED               0U
/*---------- -----------*/
#define USBD_SELF_POWERED              1U
/*---------- -----------*/
#define USBD_SUPPORT_USER_STRING       0U


/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Macros USBD_CONF_Exported_Macros
  * @brief Aliasess.
  * @{
  */

/* Memory management macros make sure to use static memory allocation */
/** Alias for memory allocation. */
#define USBD_malloc         (void *)USBD_static_malloc

/** Alias for memory release. */
#define USBD_free           USBD_static_free

/** Alias for memory set. */
#define USBD_memset         memset

/** Alias for memory copy. */
#define USBD_memcpy         memcpy

/** Alias for delay. */
#define USBD_Delay          HAL_Delay

/* DEBUG macros */

#if (USBD_DEBUG_LEVEL > 0)
#define USBD_UsrLog(...)    printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_UsrLog(...)
#endif

#if (USBD_DEBUG_LEVEL > 1)

#define USBD_ErrLog(...)    printf("ERROR: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_ErrLog(...)
#endif

#if (USBD_DEBUG_LEVEL > 2)
#define USBD_DbgLog(...)    printf("DEBUG : ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_DbgLog(...)
#endif

/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Types USBD_CONF_Exported_Types
  * @brief Types.
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_FunctionsPrototype USBD_CONF_Exported_FunctionsPrototype
  * @brief Declaration of public functions for Usb device.
  * @{
  */

/* Exported functions -------------------------------------------------------*/
void *USBD_static_malloc(uint32_t size);
void USBD_static_free(void *p);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __USBD_CONF__H__ */