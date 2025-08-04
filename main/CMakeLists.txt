file(GLOB_RECURSE ASSETS "assets/*.c")

idf_component_register(SRCS "m5stack-tab5-lvgl.c"
                            "gui.c"
                            "hal.c"
                            "app_manager.c"
                            "top_toolbar.c"
                            "side_toolbar.c"
                            ${ASSETS}
                    INCLUDE_DIRS "."
                                 "assets")
