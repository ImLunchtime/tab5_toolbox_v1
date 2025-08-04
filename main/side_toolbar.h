#ifndef SIDE_TOOLBAR_H
#define SIDE_TOOLBAR_H

#include "lvgl.h"
#include "assets/assets.h"

// 顶部工具栏高度（避免循环依赖）
#define TOP_TOOLBAR_HEIGHT 144

// 侧边工具栏配置
#define SIDE_TOOLBAR_WIDTH 104
#define SIDE_BUTTON_WIDTH 96
#define SIDE_BUTTON_HEIGHT 72
#define SIDE_BUTTON_COUNT 6

// 侧边工具栏容器
extern lv_obj_t *side_toolbar_container;

// 侧边按钮数组
extern lv_obj_t *side_buttons[SIDE_BUTTON_COUNT];

// 函数声明
void side_toolbar_init(lv_obj_t *parent);
void side_toolbar_set_callback(void (*callback)(int button_index));

#endif // SIDE_TOOLBAR_H