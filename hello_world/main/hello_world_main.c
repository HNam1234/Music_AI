/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/projdefs.h"
#include "freertos/task.h"
#include "portmacro.h"
#include "sdkconfig.h"
#include <inttypes.h>
#include <stdio.h>

void helloWorld(void *pvParameter) {
  while (1) {
    printf("Hello world 123!\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void printMyname(void *pvParameter) {
  while (1) {
    printf("My name is ESP32!\n");
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}

void app_main(void) {
  TaskFunction_t task_func = helloWorld;
  BaseType_t xReturn =
      xTaskCreate(task_func, "helloWorld", 2048, NULL, 5, NULL);
  if (xReturn != pdPASS) {
    printf("Task creation failed with error code %d\n", xReturn);
    return;
  }
  task_func = printMyname;
  xReturn = xTaskCreate(task_func, "printMyname", 2048, NULL, 5, NULL);
  if (xReturn != pdPASS) {
    printf("Task creation failed with error code %d\n", xReturn);
    return;
  }
}
