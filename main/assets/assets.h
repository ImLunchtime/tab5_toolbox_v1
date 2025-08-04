#ifndef ASSETS_H
#define ASSETS_H

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

// 顶部按钮图片声明 (从左到右)
extern const lv_image_dsc_t img_button_adc;     // ADC按钮
extern const lv_image_dsc_t img_button_gpio;    // GPIO按钮
extern const lv_image_dsc_t img_button_i2c;     // I2C按钮
extern const lv_image_dsc_t img_button_music;   // 音乐按钮
extern const lv_image_dsc_t img_button_more;    // 更多按钮

// 右侧按钮图片声明 (从上到下)
extern const lv_image_dsc_t img_control_powerdown_normal;  // 电源按钮
extern const lv_image_dsc_t img_control_sleep;             // 睡眠按钮
extern const lv_image_dsc_t img_control_battery;           // 电池按钮
extern const lv_image_dsc_t img_control_charge_05a;        // 充电按钮
extern const lv_image_dsc_t img_control_volume_5;          // 音量按钮
extern const lv_image_dsc_t img_control_brightness_8;      // 亮度按钮

#endif // ASSETS_H