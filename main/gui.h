#pragma once

#include "lvgl.h"
#include "app_manager.h"
#include "top_toolbar.h"
#include "side_toolbar.h"
#include "assets/assets.h"

/**
 * @brief 初始化GUI界面
 * 
 * @param disp LVGL显示实例
 */
void gui_init(lv_disp_t *disp);