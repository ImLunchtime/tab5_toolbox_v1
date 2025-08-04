#include "app_manager.h"
#include <string.h>

static app_info_t apps[APP_TYPE_MAX];
static lv_obj_t* content_container = NULL;
static app_type_t current_app = APP_TYPE_HOME;

// 默认应用初始化函数
static void default_home_init(lv_obj_t* parent) {
    lv_obj_t* label = lv_label_create(parent);
    lv_label_set_text(label, "欢迎使用 M5Stack Tab5");
    lv_obj_center(label);
}

static void default_settings_init(lv_obj_t* parent) {
    lv_obj_t* label = lv_label_create(parent);
    lv_label_set_text(label, "设置界面");
    lv_obj_center(label);
}

static void default_calculator_init(lv_obj_t* parent) {
    lv_obj_t* label = lv_label_create(parent);
    lv_label_set_text(label, "计算器");
    lv_obj_center(label);
}

static void default_clock_init(lv_obj_t* parent) {
    lv_obj_t* label = lv_label_create(parent);
    lv_label_set_text(label, "时钟");
    lv_obj_center(label);
}

static void default_weather_init(lv_obj_t* parent) {
    lv_obj_t* label = lv_label_create(parent);
    lv_label_set_text(label, "天气");
    lv_obj_center(label);
}

static void default_deinit(void) {
    // 默认清理函数，暂时为空
}

void app_manager_init(void) {
    // 初始化应用信息
    memset(apps, 0, sizeof(apps));
    
    // 注册默认应用
    app_manager_register(APP_TYPE_HOME, "主页", default_home_init, default_deinit);
    app_manager_register(APP_TYPE_SETTINGS, "设置", default_settings_init, default_deinit);
    app_manager_register(APP_TYPE_CALCULATOR, "计算器", default_calculator_init, default_deinit);
    app_manager_register(APP_TYPE_CLOCK, "时钟", default_clock_init, default_deinit);
    app_manager_register(APP_TYPE_WEATHER, "天气", default_weather_init, default_deinit);
}

void app_manager_set_parent(lv_obj_t* parent) {
    content_container = parent;
    // 默认显示主页
    app_manager_switch_app(APP_TYPE_HOME);
}

void app_manager_register(app_type_t app_type, const char* name, 
                         void (*init_func)(lv_obj_t* parent), 
                         void (*deinit_func)(void)) {
    if (app_type >= APP_TYPE_MAX) return;
    
    apps[app_type].type = app_type;
    apps[app_type].name = name;
    apps[app_type].init_func = init_func;
    apps[app_type].deinit_func = deinit_func;
    apps[app_type].container = NULL;
}

void app_manager_switch_app(app_type_t app_type) {
    if (app_type >= APP_TYPE_MAX || !content_container) return;
    
    // 清理当前应用
    if (apps[current_app].container) {
        if (apps[current_app].deinit_func) {
            apps[current_app].deinit_func();
        }
        lv_obj_del(apps[current_app].container);
        apps[current_app].container = NULL;
    }
    
    // 创建新应用容器
    apps[app_type].container = lv_obj_create(content_container);
    lv_obj_set_size(apps[app_type].container, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_pad_all(apps[app_type].container, 0, 0);
    lv_obj_set_style_border_width(apps[app_type].container, 0, 0);
    lv_obj_set_style_radius(apps[app_type].container, 0, 0);
    lv_obj_clear_flag(apps[app_type].container, LV_OBJ_FLAG_SCROLLABLE);
    
    // 初始化新应用
    if (apps[app_type].init_func) {
        apps[app_type].init_func(apps[app_type].container);
    }
    
    current_app = app_type;
}

app_type_t app_manager_get_current(void) {
    return current_app;
}