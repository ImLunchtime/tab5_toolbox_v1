#include "topbar.h"
#include "image_resources.h"
#include "sidebar.h"

// 顶栏按钮图片数组
static const lv_image_dsc_t* topbar_images[] = {
    &img_button_adc,
    &img_button_i2c,
    &img_button_gpio,
    &img_button_usb,
    &img_button_music,
    &img_button_more
};

// 顶栏按钮名称
static const char* topbar_button_names[] = {
    "ADC",
    "I2C",
    "GPIO",
    "USB",
    "Music",
    "More"
};

void topbar_button_event_cb(lv_event_t* e)
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

lv_obj_t* topbar_create(lv_obj_t* parent, int width)
{
    // 创建顶栏容器
    lv_obj_t* topbar = lv_obj_create(parent);
    lv_obj_set_size(topbar, width - SIDEBAR_WIDTH, TOPBAR_HEIGHT);
    lv_obj_align(topbar, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_bg_opa(topbar, LV_OPA_TRANSP, 0); // 透明背景
    lv_obj_set_style_border_width(topbar, 0, 0);
    lv_obj_set_style_radius(topbar, 0, 0);
    lv_obj_set_style_pad_all(topbar, 5, 0);
    
    // 禁用滚动
    lv_obj_clear_flag(topbar, LV_OBJ_FLAG_SCROLLABLE);
    
    // 创建顶栏按钮
    int button_count = sizeof(topbar_images) / sizeof(topbar_images[0]);
    int button_size = 128;
    int button_spacing = 10;
    int topbar_width = width - SIDEBAR_WIDTH;
    
    // 计算所有按钮的总宽度
    int total_buttons_width = button_count * button_size + (button_count - 1) * button_spacing;
    
    // 计算起始X位置（从右边开始，留出5px的右边距）
    int start_x = topbar_width - total_buttons_width - 5;
    
    for(int i = 0; i < button_count; i++) {
        lv_obj_t* btn = lv_btn_create(topbar);
        lv_obj_set_size(btn, button_size, button_size);
        
        // 按钮靠右对齐
        int btn_x = start_x + i * (button_size + button_spacing);
        lv_obj_set_pos(btn, btn_x, 8);
        
        // 设置按钮样式
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x444444), 0);
        lv_obj_set_style_border_width(btn, 1, 0);
        lv_obj_set_style_border_color(btn, lv_color_hex(0x888888), 0);
        lv_obj_set_style_radius(btn, 8, 0);
        
        // 禁用按钮滚动
        lv_obj_clear_flag(btn, LV_OBJ_FLAG_SCROLLABLE);
        
        // 创建按钮图片
        lv_obj_t* img = lv_image_create(btn);
        lv_image_set_src(img, topbar_images[i]);
        lv_obj_center(img);
        
        // 禁用图片滚动
        lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE);
        
        // 设置按钮用户数据和事件
        static int button_indices[6];
        button_indices[i] = i;
        lv_obj_set_user_data(btn, &button_indices[i]);
        lv_obj_add_event_cb(btn, topbar_button_event_cb, LV_EVENT_ALL, NULL);
    }
    
    return topbar;
}