#include "gui.h"
#include "app_manager.h"
#include "top_toolbar.h"
#include "side_toolbar.h"

// 全局变量
lv_obj_t *main_container = NULL;
lv_obj_t *content_container = NULL;

// 顶部工具栏按钮点击回调
void on_top_toolbar_clicked(int button_index)
{
    // 根据按钮索引切换应用
    switch (button_index) {
        case 0: // ADC
            app_manager_switch_app(APP_TYPE_HOME);
            break;
        case 1: // GPIO
            app_manager_switch_app(APP_TYPE_SETTINGS);
            break;
        case 2: // I2C
            app_manager_switch_app(APP_TYPE_CALCULATOR);
            break;
        case 3: // 音乐
            app_manager_switch_app(APP_TYPE_CLOCK);
            break;
        case 4: // 更多
            app_manager_switch_app(APP_TYPE_WEATHER);
            break;
        default:
            break;
    }
}

// 侧边工具栏按钮点击回调
void on_side_toolbar_clicked(int button_index)
{
    // 根据按钮索引执行相应功能
    switch (button_index) {
        case 0: // 电源
            // 电源管理功能
            break;
        case 1: // 睡眠
            // 睡眠功能
            break;
        case 2: // 电池
            // 电池状态显示
            break;
        case 3: // 充电
            // 充电状态显示
            break;
        case 4: // 音量
            // 音量控制
            break;
        case 5: // 亮度
            // 亮度控制
            break;
        default:
            break;
    }
}

void gui_init(lv_disp_t *disp)
{
    // 获取活动屏幕
    lv_obj_t *scr = lv_disp_get_scr_act(disp);
    
    // 设置屏幕背景为灰色
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x808080), 0);  // 灰色背景
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);
    
    // 创建主容器
    main_container = lv_obj_create(scr);
    lv_obj_set_size(main_container, LV_PCT(100), LV_PCT(100));
    lv_obj_set_pos(main_container, 0, 0);
    lv_obj_set_style_bg_opa(main_container, LV_OPA_TRANSP, 0);  // 透明背景
    lv_obj_set_style_border_width(main_container, 0, 0);        // 无边框
    lv_obj_set_style_radius(main_container, 0, 0);              // 无圆角
    lv_obj_set_style_pad_all(main_container, 0, 0);             // 无内边距
    
    // 初始化应用管理器
    app_manager_init();
    
    // 创建内容区域容器
    content_container = lv_obj_create(main_container);
    lv_obj_set_size(content_container, 
                     lv_obj_get_width(main_container) - SIDE_TOOLBAR_WIDTH, 
                     lv_obj_get_height(main_container) - TOP_TOOLBAR_HEIGHT);
    lv_obj_set_pos(content_container, 0, TOP_TOOLBAR_HEIGHT);
    lv_obj_set_style_bg_opa(content_container, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(content_container, 0, 0);
    lv_obj_set_style_radius(content_container, 0, 0);
    lv_obj_set_style_pad_all(content_container, 0, 0);
    
    // 设置应用管理器的父容器
    app_manager_set_parent(content_container);
    
    // 初始化顶部工具栏
    top_toolbar_init(main_container);
    top_toolbar_set_callback(on_top_toolbar_clicked);
    
    // 初始化侧边工具栏
    side_toolbar_init(main_container);
    side_toolbar_set_callback(on_side_toolbar_clicked);
    
    // 显示默认应用
    app_manager_switch_app(APP_TYPE_HOME);
}