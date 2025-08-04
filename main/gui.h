#ifndef GUI_H
#define GUI_H

#include "lvgl.h"

// 获取屏幕尺寸
int gui_get_screen_width(void);
int gui_get_screen_height(void);

#endif // GUI_H

/**
 * @brief Initialize the GUI with a centered button
 * 
 * @param disp LVGL display instance
 */
void gui_init(lv_disp_t *disp);