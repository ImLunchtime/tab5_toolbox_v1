#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "lvgl.h"

#define SIDEBAR_WIDTH 100

// 侧边栏初始化函数
lv_obj_t* sidebar_create(lv_obj_t* parent);

// 侧边栏按钮事件回调
void sidebar_button_event_cb(lv_event_t* e);

#endif // SIDEBAR_H