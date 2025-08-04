#include "app_gpio.h"

static lv_obj_t* gpio_container = NULL;

void app_gpio_init(lv_obj_t* parent)
{
    // 清空父容器
    lv_obj_clean(parent);
    
    // 创建GPIO App容器
    gpio_container = lv_obj_create(parent);
    lv_obj_set_size(gpio_container, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_color(gpio_container, lv_color_white(), 0);
    lv_obj_set_style_border_width(gpio_container, 0, 0);
    lv_obj_set_style_radius(gpio_container, 0, 0);
    lv_obj_set_style_pad_all(gpio_container, 20, 0);
    
    // 创建标题
    lv_obj_t* title = lv_label_create(gpio_container);
    lv_label_set_text(title, "GPIO App");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_24, 0);
    lv_obj_set_style_text_color(title, lv_color_hex(0x333333), 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 0);
    
    // 创建内容区域
    lv_obj_t* content = lv_label_create(gpio_container);
    lv_label_set_text(content, "GPIO Control App\n\n"
                              "This app will provide:\n"
                              "• Pin configuration\n"
                              "• Digital I/O control\n"
                              "• PWM generation\n"
                              "• Interrupt handling\n\n"
                              "Currently under development...");
    lv_obj_set_style_text_align(content, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_align(content, LV_ALIGN_CENTER, 0, 20);
}

void app_gpio_destroy(void)
{
    if(gpio_container) {
        lv_obj_del(gpio_container);
        gpio_container = NULL;
    }
}