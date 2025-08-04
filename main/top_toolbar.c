#include "top_toolbar.h"

// 全局变量
lv_obj_t *top_toolbar_container = NULL;
lv_obj_t *top_buttons[TOP_BUTTON_COUNT] = {NULL};

// 回调函数指针
static void (*button_callback)(int button_index) = NULL;

// 顶部按钮图片数组
static const lv_image_dsc_t *top_button_images[TOP_BUTTON_COUNT] = {
    &img_button_adc,     // ADC按钮
    &img_button_gpio,    // GPIO按钮
    &img_button_i2c,     // I2C按钮
    &img_button_music,   // 音乐按钮
    &img_button_more     // 更多按钮
};

// 顶部按钮标签数组
static const char *top_button_labels[TOP_BUTTON_COUNT] = {
    "ADC",
    "GPIO", 
    "I2C",
    "音乐",
    "更多"
};

// 按钮事件处理函数
static void top_button_event_cb(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    
    if (code == LV_EVENT_CLICKED) {
        // 查找按钮索引
        for (int i = 0; i < TOP_BUTTON_COUNT; i++) {
            if (top_buttons[i] == btn) {
                if (button_callback) {
                    button_callback(i);
                }
                break;
            }
        }
    }
}

void top_toolbar_init(lv_obj_t *parent)
{
    // 创建顶部工具栏容器
    top_toolbar_container = lv_obj_create(parent);
    lv_obj_set_size(top_toolbar_container, LV_PCT(100), TOP_TOOLBAR_HEIGHT);
    lv_obj_set_pos(top_toolbar_container, 0, 0);
    
    // 设置容器样式
    lv_obj_set_style_bg_opa(top_toolbar_container, LV_OPA_TRANSP, 0);  // 透明背景
    lv_obj_set_style_border_width(top_toolbar_container, 0, 0);        // 无边框
    lv_obj_set_style_radius(top_toolbar_container, 0, 0);              // 无圆角
    lv_obj_set_style_pad_all(top_toolbar_container, 8, 0);             // 内边距
    
    // 设置flex布局
    lv_obj_set_flex_flow(top_toolbar_container, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(top_toolbar_container, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    // 创建按钮
    for (int i = 0; i < TOP_BUTTON_COUNT; i++) {
        // 创建按钮容器
        lv_obj_t *btn_container = lv_obj_create(top_toolbar_container);
        lv_obj_set_size(btn_container, TOP_BUTTON_SIZE, TOP_BUTTON_SIZE);
        lv_obj_set_style_bg_opa(btn_container, LV_OPA_TRANSP, 0);
        lv_obj_set_style_border_width(btn_container, 0, 0);
        lv_obj_set_style_radius(btn_container, 0, 0);
        lv_obj_set_style_pad_all(btn_container, 0, 0);
        
        // 设置flex布局
        lv_obj_set_flex_flow(btn_container, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_flex_align(btn_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        
        // 创建图片按钮
        lv_obj_t *btn = lv_imagebutton_create(btn_container);
        lv_imagebutton_set_src(btn, LV_IMAGEBUTTON_STATE_RELEASED, NULL, top_button_images[i], NULL);
        lv_imagebutton_set_src(btn, LV_IMAGEBUTTON_STATE_PRESSED, NULL, top_button_images[i], NULL);
        lv_obj_set_size(btn, 96, 96);  // 图片按钮大小
        
        // 添加事件处理
        lv_obj_add_event_cb(btn, top_button_event_cb, LV_EVENT_CLICKED, NULL);
        
        // 创建标签
        lv_obj_t *label = lv_label_create(btn_container);
        lv_label_set_text(label, top_button_labels[i]);
        lv_obj_set_style_text_font(label, &lv_font_montserrat_24, 0);  // 使用中文字体
        lv_obj_set_style_text_color(label, lv_color_white(), 0);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
        
        // 保存按钮引用
        top_buttons[i] = btn;
    }
}

void top_toolbar_set_callback(void (*callback)(int button_index))
{
    button_callback = callback;
}