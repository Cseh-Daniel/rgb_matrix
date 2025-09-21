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

void app_main(void)
{
    esp_log_level_set("*", ESP_LOG_NONE);
    printf("Hello world!\n");
    vTaskDelay(10000 / portTICK_PERIOD_MS);



    esp_restart();
}
