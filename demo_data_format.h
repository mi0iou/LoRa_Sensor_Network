/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    demo_data_format.h
  * @author  MCD Application Team
  * @brief   Header with data format definitions for STM32WL Concentrator Demo.
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
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEMO_DATA_FORMAT_H__
#define __DEMO_DATA_FORMAT_H__

#include <stdint.h>
#include "stm32wlxx_hal.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief Structure with measurement data.
  * Sent in DEMO_packet_sensor_t.
  * This data structure is for version 1.0.
  */
typedef __PACKED_STRUCT
{
  int16_t temperature;  /**<Temperature [0.01 `C]*/
  uint8_t voltage;      /**<Voltage on the MCU [0.05 V]*/
  uint8_t airquality;   /**<Air Quality*/
} DEMO_data_1_0_t;

/**Error values for DEMO_data_1_0_t*/
#define DEMO_DATA_1_0_ERROR_TEMPERATURE       INT16_MAX
#define DEMO_DATA_1_0_ERROR_VOLTAGE           UINT8_MAX
#define DEMO_DATA_1_0_ERROR_AIRQUALITY        UINT8_MAX

/**
  * @brief Structure with measurement data.
  * Sent in DEMO_packet_sensor_t.
  * This data structure is for version 1.1. */

typedef __PACKED_STRUCT
{
  int16_t temperature;
  uint16_t pressure;
  int32_t yaw :10;
  int32_t pitch :10;
  int32_t roll :10;
  int32_t :2;
  uint8_t humidity;
  uint8_t voltage;
  uint16_t distance:12;
  uint16_t activity:4;
  uint16_t step_count;
  uint16_t swipe_count;
  uint16_t acceleration_avg;
  uint16_t acceleration_max;

} DEMO_data_1_1_t;

#define DEMO_DATA_1_1_ERROR_TEMPERATURE       DEMO_DATA_1_0_ERROR_TEMPERATURE
#define DEMO_DATA_1_1_ERROR_PRESSURE          UINT16_MAX
#define DEMO_DATA_1_1_ERROR_YAW               (-512)
#define DEMO_DATA_1_1_ERROR_PITCH             (-512)
#define DEMO_DATA_1_1_ERROR_ROLL              (-512)
#define DEMO_DATA_1_1_ERROR_HUMIDITY          UINT8_MAX
#define DEMO_DATA_1_1_ERROR_ACTIVITY          (0xFU)
#define DEMO_DATA_1_1_ERROR_DISTANCE          (0xFFFU)
#define DEMO_DATA_1_1_ERROR_ACCELERATION      UINT16_MAX
#define DEMO_DATA_1_1_ERROR_VOLTAGE           DEMO_DATA_1_0_ERROR_VOLTAGE


#ifdef __cplusplus
}
#endif

#endif /* __DEMO_DATA_FORMAT_H__ */
