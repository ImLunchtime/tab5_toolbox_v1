#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include "lvgl.h"

// App类型枚举
typedef enum {
    APP_ADC = 0,
    APP_I2C,
    APP_GPIO,
    APP_USB,
    APP_MUSIC,
    APP_MORE_MENU,  // 更多App菜单（不算真正的App）
    APP_COUNT
} app_type_t;

// App结构体
typedef struct {
    app_type_t type;
    const char* name;
    lv_obj_t* container;
    bool is_active;
    void (*init_func)(lv_obj_t* parent);
    void (*destroy_func)(void);
} app_t;

// App管理器初始化
void app_manager_init(lv_obj_t* app_container);

// 切换到指定App
void app_manager_switch_to_app(app_type_t app_type);

// 获取当前活动的App
app_type_t app_manager_get_current_app(void);

// 关闭当前App，返回到默认状态
void app_manager_close_current_app(void);

#endif // APP_MANAGER_H