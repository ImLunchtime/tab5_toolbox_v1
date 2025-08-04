#include "app_container.h"
#include "sidebar.h"
#include "topbar.h"

lv_obj_t* app_container_create(lv_obj_t* parent, int width, int height, int y_offset)
{
    // 创建应用容器
    lv_obj_t* app_container = lv_obj_create(parent);
    lv_obj_set_size(app_container, width - SIDEBAR_WIDTH - 10, height - y_offset - 10);
    lv_obj_set_pos(app_container, 5, y_offset + 5);
    
    // 设置容器样式
    lv_obj_set_style_bg_color(app_container, lv_color_white(), 0);
    lv_obj_set_style_border_width(app_container, 2, 0);
    lv_obj_set_style_border_color(app_container, lv_color_hex(0xCCCCCC), 0);
    lv_obj_set_style_radius(app_container, 10, 0);
    lv_obj_set_style_pad_all(app_container, 10, 0);
    
    // 添加一个标签作为占位符
    lv_obj_t* label = lv_label_create(app_container);
    lv_label_set_text(label, "App Container\n\nThis is where your app content will go.");
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_center(label);
    
    return app_container;
}