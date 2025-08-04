#include "more_menu.h"

static lv_obj_t* more_container = NULL;

void more_menu_init(lv_obj_t* parent)
{
    // 清空父容器
    lv_obj_clean(parent);
    
    // 创建更多菜单容器
    more_container = lv_obj_create(parent);
    lv_obj_set_size(more_container, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_color(more_container, lv_color_white(), 0);
    lv_obj_set_style_border_width(more_container, 0, 0);
    lv_obj_set_style_radius(more_container, 0, 0);
    lv_obj_set_style_pad_all(more_container, 20, 0);
    
    // 创建标题
    lv_obj_t* title = lv_label_create(more_container);
    lv_label_set_text(title, "More Apps");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_24, 0);
    lv_obj_set_style_text_color(title, lv_color_hex(0x333333), 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 0);
    
    // 创建内容区域
    lv_obj_t* content = lv_label_create(more_container);
    lv_label_set_text(content, "Additional Apps Menu\n\n"
                              "Future apps will include:\n"
                              "• System Settings\n"
                              "• File Manager\n"
                              "• Network Tools\n"
                              "• Calculator\n"
                              "• Terminal\n"
                              "• System Monitor\n\n"
                              "Coming soon...");
    lv_obj_set_style_text_align(content, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_align(content, LV_ALIGN_CENTER, 0, 20);
}

void more_menu_destroy(void)
{
    if(more_container) {
        lv_obj_del(more_container);
        more_container = NULL;
    }
}