#ifndef APP_CONTAINER_H
#define APP_CONTAINER_H

#include "lvgl.h"

// 应用容器初始化函数
lv_obj_t* app_container_create(lv_obj_t* parent, int width, int height, int y_offset);

#endif // APP_CONTAINER_H