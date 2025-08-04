#include "gui.h"
#include "sidebar.h"
#include "topbar.h"
#include "app_container.h"

// 屏幕尺寸（这些值应该根据实际硬件调整）
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

static lv_obj_t* main_screen;
static lv_obj_t* sidebar_obj;
static lv_obj_t* topbar_obj;
static lv_obj_t* app_container_obj;

int gui_get_screen_width(void)
{
    return SCREEN_WIDTH;
}

int gui_get_screen_height(void)
{
    return SCREEN_HEIGHT;
}

void gui_init(lv_disp_t *disp)
{
    // 获取当前活动屏幕
    main_screen = lv_screen_active();
    
    // 设置主屏幕背景为灰色
    lv_obj_set_style_bg_color(main_screen, lv_color_hex(0x808080), 0);
    
    // 创建侧边栏
    sidebar_obj = sidebar_create(main_screen);
    
    // 创建顶栏
    topbar_obj = topbar_create(main_screen, SCREEN_WIDTH);
    
    // 创建应用容器
    app_container_obj = app_container_create(main_screen, SCREEN_WIDTH, SCREEN_HEIGHT, TOPBAR_HEIGHT);
}