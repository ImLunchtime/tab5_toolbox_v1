#ifndef APP_USB_H
#define APP_USB_H

#include "lvgl.h"

// USB App初始化
void app_usb_init(lv_obj_t* parent);

// USB App销毁
void app_usb_destroy(void);

#endif // APP_USB_H