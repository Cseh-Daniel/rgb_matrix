/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "neopixel.h"

#define TAG "neopixel_test"
#define PIXEL_COUNT  64
#if defined(CONFIG_IDF_TARGET_ESP32S3)
   #define NEOPIXEL_PIN GPIO_NUM_48
#elif defined(CONFIG_IDF_TARGET_ESP32C6)
   #define NEOPIXEL_PIN GPIO_NUM_8
#else
   #define NEOPIXEL_PIN GPIO_NUM_27
#endif

#if !defined(MAX)
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#endif
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

static bool test1(uint32_t iterations)
{
   tNeopixelContext neopixel = neopixel_Init(PIXEL_COUNT, NEOPIXEL_PIN);
   tNeopixel pixel[] =
   {
       { 0, NP_RGB(50, 0,  0) }, /* red */
       { 0, NP_RGB(0,  50, 0) }, /* green */
       { 0, NP_RGB(0,  0, 50) }, /* blue */
       { 0, NP_RGB(0,  0,  0) }, /* off */
       { 1, NP_RGB(50, 0,  0) }, /* red */
       { 1, NP_RGB(0,  50, 0) }, /* green */
       { 1, NP_RGB(0,  0, 50) }, /* blue */
       { 1, NP_RGB(0,  0,  0) }, /* off */
   };

   if(NULL == neopixel)
   {
      ESP_LOGE(TAG, "[%s] Initialization failed\n", __func__);
      return false;
   }

   ESP_LOGI(TAG, "[%s] Starting", __func__);
   for(int iter = 0; iter < iterations; ++iter)
   {
      for(int i = 0; i < ARRAY_SIZE(pixel); ++i)
      {
         neopixel_SetPixel(neopixel, &pixel[i], 1);
         vTaskDelay(pdMS_TO_TICKS(125));
      }
   }
   ESP_LOGI(TAG, "[%s] Finished", __func__);

   neopixel_Deinit(neopixel);
   return true;
}


void app_main(void)
{
    test1(2);
    esp_restart();
}
