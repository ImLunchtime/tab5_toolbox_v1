#include "app_i2c.h"

static lv_obj_t* i2c_container = NULL;

void app_i2c_init(lv_obj_t* parent)
{
    // 清空父容器
    lv_obj_clean(parent);
    
    // 创建I2C App容器
    i2c_container = lv_obj_create(parent);
    lv_obj_set_size(i2c_container, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_color(i2c_container, lv_color_white(), 0);
    lv_obj_set_style_border_width(i2c_container, 0, 0);
    lv_obj_set_style_radius(i2c_container, 0, 0);
    lv_obj_set_style_pad_all(i2c_container, 20, 0);
    
    // 创建标题
    lv_obj_t* title = lv_label_create(i2c_container);
    lv_label_set_text(title, "I2C App");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_24, 0);
    lv_obj_set_style_text_color(title, lv_color_hex(0x333333), 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 0);
    
    // 创建内容区域
    lv_obj_t* content = lv_label_create(i2c_container);
    lv_label_set_text(content, "I2C Communication App\n\n"
                              "This app will provide:\n"
                              "• I2C device scanning\n"
                              "• Read/Write operations\n"
                              "• Device configuration\n"
                              "• Protocol analysis\n\n"
                              "Currently under development...");
    lv_obj_set_style_text_align(content, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_align(content, LV_ALIGN_CENTER, 0, 20);
}

void app_i2c_destroy(void)
{
    if(i2c_container) {
        lv_obj_del(i2c_container);
        i2c_container = NULL;
    }
}