#ifndef TOP_TOOLBAR_H
#define TOP_TOOLBAR_H

#include "lvgl.h"
#include "assets/assets.h"

// 顶部工具栏配置
#define TOP_TOOLBAR_HEIGHT 144
#define TOP_BUTTON_SIZE 128
#define TOP_BUTTON_COUNT 5

// 顶部工具栏容器
extern lv_obj_t *top_toolbar_container;

// 顶部按钮数组
extern lv_obj_t *top_buttons[TOP_BUTTON_COUNT];

// 函数声明
void top_toolbar_init(lv_obj_t *parent);
void top_toolbar_set_callback(void (*callback)(int button_index));

#endif // TOP_TOOLBAR_H