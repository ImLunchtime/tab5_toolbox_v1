#include "app_manager.h"
#include "app_adc.h"
#include "app_i2c.h"
#include "app_gpio.h"
#include "app_usb.h"
#include "app_music.h"
#include "more_menu.h"

static lv_obj_t* main_app_container = NULL;
static app_t apps[APP_COUNT];
static app_type_t current_app = APP_COUNT; // 无效值表示没有活动App

// 初始化所有App的信息
static void init_app_info(void)
{
    apps[APP_ADC] = (app_t){
        .type = APP_ADC,
        .name = "ADC App",
        .container = NULL,
        .is_active = false,
        .init_func = app_adc_init,
        .destroy_func = app_adc_destroy
    };
    
    apps[APP_I2C] = (app_t){
        .type = APP_I2C,
        .name = "I2C App",
        .container = NULL,
        .is_active = false,
        .init_func = app_i2c_init,
        .destroy_func = app_i2c_destroy
    };
    
    apps[APP_GPIO] = (app_t){
        .type = APP_GPIO,
        .name = "GPIO App",
        .container = NULL,
        .is_active = false,
        .init_func = app_gpio_init,
        .destroy_func = app_gpio_destroy
    };
    
    apps[APP_USB] = (app_t){
        .type = APP_USB,
        .name = "USB App",
        .container = NULL,
        .is_active = false,
        .init_func = app_usb_init,
        .destroy_func = app_usb_destroy
    };
    
    apps[APP_MUSIC] = (app_t){
        .type = APP_MUSIC,
        .name = "Music App",
        .container = NULL,
        .is_active = false,
        .init_func = app_music_init,
        .destroy_func = app_music_destroy
    };
    
    apps[APP_MORE_MENU] = (app_t){
        .type = APP_MORE_MENU,
        .name = "More Apps",
        .container = NULL,
        .is_active = false,
        .init_func = more_menu_init,
        .destroy_func = more_menu_destroy
    };
}

void app_manager_init(lv_obj_t* app_container)
{
    main_app_container = app_container;
    init_app_info();
    current_app = APP_COUNT; // 初始状态没有活动App
}

void app_manager_switch_to_app(app_type_t app_type)
{
    if(app_type >= APP_COUNT) return;
    
    // 关闭当前App
    app_manager_close_current_app();
    
    // 启动新App
    if(apps[app_type].init_func) {
        apps[app_type].init_func(main_app_container);
        apps[app_type].is_active = true;
        current_app = app_type;
    }
}

app_type_t app_manager_get_current_app(void)
{
    return current_app;
}

void app_manager_close_current_app(void)
{
    if(current_app < APP_COUNT && apps[current_app].is_active) {
        if(apps[current_app].destroy_func) {
            apps[current_app].destroy_func();
        }
        apps[current_app].is_active = false;
        apps[current_app].container = NULL;
    }
    current_app = APP_COUNT;
}