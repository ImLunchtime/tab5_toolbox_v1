#ifndef TOPBAR_H
#define TOPBAR_H

#include "lvgl.h"

#define TOPBAR_HEIGHT 144

// 顶栏初始化函数
lv_obj_t* topbar_create(lv_obj_t* parent, int width);

// 顶栏按钮事件回调
void topbar_button_event_cb(lv_event_t* e);

#endif // TOPBAR_H