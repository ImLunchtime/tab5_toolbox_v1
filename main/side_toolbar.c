#include "side_toolbar.h"

// 全局变量
lv_obj_t *side_toolbar_container = NULL;
lv_obj_t *side_buttons[SIDE_BUTTON_COUNT] = {NULL};

// 回调函数指针
static void (*button_callback)(int button_index) = NULL;

// 侧边按钮图片数组
static const lv_image_dsc_t *side_button_images[SIDE_BUTTON_COUNT] = {
    &img_control_powerdown_normal,  // 电源按钮
    &img_control_sleep,             // 睡眠按钮
    &img_control_battery,           // 电池按钮
    &img_control_charge_05a,        // 充电按钮
    &img_control_volume_5,          // 音量按钮
    &img_control_brightness_8       // 亮度按钮
};

// 侧边按钮标签数组
static const char *side_button_labels[SIDE_BUTTON_COUNT] = {
    "电源",
    "睡眠",
    "电池",
    "充电",
    "音量",
    "亮度"
};

// 按钮事件处理函数
static void side_button_event_cb(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    
    if (code == LV_EVENT_CLICKED) {
        // 查找按钮索引
        for (int i = 0; i < SIDE_BUTTON_COUNT; i++) {
            if (side_buttons[i] == btn) {
                if (button_callback) {
                    button_callback(i);
                }
                break;
            }
        }
    }
}

void side_toolbar_init(lv_obj_t *parent)
{
    // 获取父容器尺寸
    lv_coord_t parent_height = lv_obj_get_height(parent);
    
    // 创建侧边工具栏容器
    side_toolbar_container = lv_obj_create(parent);
    lv_obj_set_size(side_toolbar_container, SIDE_TOOLBAR_WIDTH, parent_height - TOP_TOOLBAR_HEIGHT);
    lv_obj_set_pos(side_toolbar_container, lv_obj_get_width(parent) - SIDE_TOOLBAR_WIDTH, TOP_TOOLBAR_HEIGHT);
    
    // 设置容器样式
    lv_obj_set_style_bg_color(side_toolbar_container, lv_color_black(), 0);   // 黑色背景
    lv_obj_set_style_bg_opa(side_toolbar_container, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(side_toolbar_container, 0, 0);              // 无边框
    lv_obj_set_style_radius(side_toolbar_container, 0, 0);                    // 无圆角
    lv_obj_set_style_pad_all(side_toolbar_container, 4, 0);                   // 内边距
    
    // 设置flex布局
    lv_obj_set_flex_flow(side_toolbar_container, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(side_toolbar_container, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    // 创建按钮
    for (int i = 0; i < SIDE_BUTTON_COUNT; i++) {
        // 创建按钮容器
        lv_obj_t *btn_container = lv_obj_create(side_toolbar_container);
        lv_obj_set_size(btn_container, SIDE_BUTTON_WIDTH, SIDE_BUTTON_HEIGHT + 20);  // 额外高度给标签
        lv_obj_set_style_bg_opa(btn_container, LV_OPA_TRANSP, 0);
        lv_obj_set_style_border_width(btn_container, 0, 0);
        lv_obj_set_style_radius(btn_container, 0, 0);
        lv_obj_set_style_pad_all(btn_container, 0, 0);
        
        // 设置flex布局
        lv_obj_set_flex_flow(btn_container, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_flex_align(btn_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        
        // 创建图片按钮
        lv_obj_t *btn = lv_imagebutton_create(btn_container);
        lv_imagebutton_set_src(btn, LV_IMAGEBUTTON_STATE_RELEASED, NULL, side_button_images[i], NULL);
        lv_imagebutton_set_src(btn, LV_IMAGEBUTTON_STATE_PRESSED, NULL, side_button_images[i], NULL);
        lv_obj_set_size(btn, 64, 48);  // 图片按钮大小
        
        // 添加事件处理
        lv_obj_add_event_cb(btn, side_button_event_cb, LV_EVENT_CLICKED, NULL);
        
        // 创建标签
        lv_obj_t *label = lv_label_create(btn_container);
        lv_label_set_text(label, side_button_labels[i]);
        lv_obj_set_style_text_font(label, &lv_font_montserrat_24, 0);  // 使用中文字体
        lv_obj_set_style_text_color(label, lv_color_white(), 0);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
        
        // 保存按钮引用
        side_buttons[i] = btn;
    }
}

void side_toolbar_set_callback(void (*callback)(int button_index))
{
    button_callback = callback;
}