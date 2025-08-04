#pragma once

#include "lvgl.h"

// 应用类型定义
typedef enum {
    APP_TYPE_HOME = 0,
    APP_TYPE_SETTINGS,
    APP_TYPE_CALCULATOR,
    APP_TYPE_CLOCK,
    APP_TYPE_WEATHER,
    APP_TYPE_MAX
} app_type_t;

// 应用结构体
typedef struct {
    app_type_t type;
    const char* name;
    lv_obj_t* container;
    void (*init_func)(lv_obj_t* parent);
    void (*deinit_func)(void);
} app_info_t;

/**
 * @brief 初始化应用管理器
 * @param content_container 内容容器，用于显示应用界面
 */
void app_manager_init(void);

void app_manager_set_parent(lv_obj_t* parent);

/**
 * @brief 切换到指定应用
 * @param app_type 应用类型
 */
void app_manager_switch_app(app_type_t app_type);

/**
 * @brief 获取当前活动的应用类型
 * @return 当前应用类型
 */
app_type_t app_manager_get_current(void);

/**
 * @brief 注册应用
 * @param app_type 应用类型
 * @param name 应用名称
 * @param init_func 初始化函数
 * @param deinit_func 清理函数
 */
void app_manager_register(app_type_t app_type, const char* name, 
                         void (*init_func)(lv_obj_t* parent), 
                         void (*deinit_func)(void));