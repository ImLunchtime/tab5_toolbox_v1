#include "sidebar.h"
#include "image_resources.h"

// 侧边栏按钮图片数组
static const lv_image_dsc_t* sidebar_images[] = {
    &img_control_powerdown_normal,
    &img_control_sleep,
    &img_control_battery,
    &img_control_charge_05a,
    &img_control_wifi,
    &img_control_volume_5,
    &img_control_brightness_8
};

// 侧边栏按钮名称
static const char* sidebar_button_names[] = {
    "Power",
    "Sleep",
    "Battery",
    "Charge",
    "WiFi",
    "Volume",
    "Brightness"
};

void sidebar_button_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* btn = lv_event_get_target(e);
    
    // 获取按钮内的图片对象
    lv_obj_t* img = lv_obj_get_child(btn, 0);
    
    if(code == LV_EVENT_PRESSED) {
        // 按钮按下时，将图片染色为暗色
        lv_obj_set_style_image_recolor_opa(img, LV_OPA_50, 0);
        lv_obj_set_style_image_recolor(img, lv_color_black(), 0);
    }
    else if(code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
        // 按钮释放时，恢复图片原色
        lv_obj_set_style_image_recolor_opa(img, LV_OPA_TRANSP, 0);
    }
    else if(code == LV_EVENT_CLICKED) {
        // 获取按钮的用户数据（按钮索引）
        int* btn_index = (int*)lv_obj_get_user_data(btn);
        if(btn_index) {
            // 这里可以添加具体的按钮功能
            // 目前只是占位符
        }
    }
}

lv_obj_t* sidebar_create(lv_obj_t* parent)
{
    // 创建侧边栏容器
    lv_obj_t* sidebar = lv_obj_create(parent);
    lv_obj_set_size(sidebar, SIDEBAR_WIDTH, LV_PCT(100));
    lv_obj_align(sidebar, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(sidebar, lv_color_black(), 0);
    lv_obj_set_style_border_width(sidebar, 0, 0);
    lv_obj_set_style_radius(sidebar, 0, 0);
    lv_obj_set_style_pad_all(sidebar, 2, 0);
    
    // 禁用滚动
    lv_obj_clear_flag(sidebar, LV_OBJ_FLAG_SCROLLABLE);
    
    // 创建侧边栏按钮
    int button_count = sizeof(sidebar_images) / sizeof(sidebar_images[0]);
    int button_height = 72;
    int button_spacing = 5;
    
    for(int i = 0; i < button_count; i++) {
        lv_obj_t* btn = lv_btn_create(sidebar);
        lv_obj_set_size(btn, 96, button_height);
        lv_obj_set_pos(btn, 2, i * (button_height + button_spacing) + 5);
        
        // 设置按钮样式
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x333333), 0);
        lv_obj_set_style_border_width(btn, 1, 0);
        lv_obj_set_style_border_color(btn, lv_color_hex(0x666666), 0);
        lv_obj_set_style_radius(btn, 5, 0);
        
        // 禁用按钮滚动
        lv_obj_clear_flag(btn, LV_OBJ_FLAG_SCROLLABLE);
        
        // 创建按钮图片
        lv_obj_t* img = lv_image_create(btn);
        lv_image_set_src(img, sidebar_images[i]);
        lv_obj_center(img);
        
        // 禁用图片滚动
        lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE);
        
        // 设置按钮用户数据和事件
        static int button_indices[7];
        button_indices[i] = i;
        lv_obj_set_user_data(btn, &button_indices[i]);
        lv_obj_add_event_cb(btn, sidebar_button_event_cb, LV_EVENT_ALL, NULL);
    }
    
    return sidebar;
}