#ifndef APP_I2C_H
#define APP_I2C_H

#include "lvgl.h"

// I2C App初始化
void app_i2c_init(lv_obj_t* parent);

// I2C App销毁
void app_i2c_destroy(void);

#endif // APP_I2C_H