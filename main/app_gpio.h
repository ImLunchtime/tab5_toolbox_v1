#ifndef APP_GPIO_H
#define APP_GPIO_H

#include "lvgl.h"

// GPIO App初始化
void app_gpio_init(lv_obj_t* parent);

// GPIO App销毁
void app_gpio_destroy(void);

#endif // APP_GPIO_H