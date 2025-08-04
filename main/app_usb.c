#include "app_usb.h"

static lv_obj_t* usb_container = NULL;

void app_usb_init(lv_obj_t* parent)
{
    // 清空父容器
    lv_obj_clean(parent);
    
    // 创建USB App容器
    usb_container = lv_obj_create(parent);
    lv_obj_set_size(usb_container, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_color(usb_container, lv_color_white(), 0);
    lv_obj_set_style_border_width(usb_container, 0, 0);
    lv_obj_set_style_radius(usb_container, 0, 0);
    lv_obj_set_style_pad_all(usb_container, 20, 0);
    
    // 创建标题
    lv_obj_t* title = lv_label_create(usb_container);
    lv_label_set_text(title, "USB App");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_24, 0);
    lv_obj_set_style_text_color(title, lv_color_hex(0x333333), 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 0);
    
    // 创建内容区域
    lv_obj_t* content = lv_label_create(usb_container);
    lv_label_set_text(content, "USB Communication App\n\n"
                              "This app will provide:\n"
                              "• USB device management\n"
                              "• Data transfer\n"
                              "• Device enumeration\n"
                              "• Protocol debugging\n\n"
                              "Currently under development...");
    lv_obj_set_style_text_align(content, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_align(content, LV_ALIGN_CENTER, 0, 20);
}

void app_usb_destroy(void)
{
    if(usb_container) {
        lv_obj_del(usb_container);
        usb_container = NULL;
    }
}