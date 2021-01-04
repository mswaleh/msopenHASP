#include "hasp_drv_touch.h"
#include "hasp/hasp.h"
#include "lvgl.h"

#if TOUCH_DRIVER == 2046
    #if defined(USE_FSMC)
    #else
        #include "tft_espi_drv.h"
    #endif

#elif TOUCH_DRIVER == 2046
    #include "indev/XPT2046.h"
#elif TOUCH_DRIVER == 0x2046B
    #include "hasp_drv_xpt2046.h"
#elif TOUCH_DRIVER == 911
    #include "hasp_drv_gt911.h"
#elif TOUCH_DRIVER == 0xADC
    #include "hasp_drv_ft6336u.h"
#elif TOUCH_DRIVER == 5206
    #include "hasp_drv_ft5206.h"
#elif TOUCH_DRIVER == 6336
    #include "hasp_drv_ft6336u.h"
#else
//#include "tp_i2c.h"
//#include "ft6x36.h"
#endif

#include "../hasp/hasp.h" // for hasp_sleep_state
extern uint8_t hasp_sleep_state;

void drv_touch_init(uint8_t rotation)
{
#if TOUCH_DRIVER == 2046 // XPT2046 Resistive touch panel driver
    #if defined(USE_FSMC)
    xpt2046_init(rotation);
    #else
        // The display driver takes care of all initializations
        // tft_espi_init(rotation);
    #endif

#elif TOUCH_DRIVER == 911
    GT911_init();

#elif TOUCH_DRIVER == 0xADC // Analog Digital Touch Conroller
    // Touch_init();

#elif TOUCH_DRIVER == 5206
    FT5206_init();

#elif TOUCH_DRIVER == 6336
    FT6336U_init();

#else
    // xpt2046_alt_drv_read(indev_driver, data);
    // xpt2046_read(indev_driver, data);
    // if(data->state && guiSleeping != HASP_SLEEP_OFF) guiCheckSleep();
#endif
}

static inline bool drv_touchpad_getXY(int16_t * touchX, int16_t * touchY)
{
#if TOUCH_DRIVER == 2046 // XPT2046 Resistive touch panel driver
    return tft_espi_get_touch(touchX, touchY, 300u);

#elif TOUCH_DRIVER == 0x2046B
    return XPT2046_getXY(touchX, touchY, true);

#elif TOUCH_DRIVER == 911
    return GT911_getXY(touchX, touchY, true);

#elif TOUCH_DRIVER == 0xADC // Analog Digital Touch Conroller
    return Touch_getXY(touchX, touchY, false);

#elif TOUCH_DRIVER == 5206
    return FT5206_getXY(touchX, touchY, true);

#elif TOUCH_DRIVER == 6336
    return FT6336U_getXY(touchX, touchY, true);

#else
    // xpt2046_alt_drv_read(indev_driver, data);
    // xpt2046_read(indev_driver, data);
    // if(data->state && guiSleeping != HASP_SLEEP_OFF) guiCheckSleep();
    return false;
#endif
}

bool IRAM_ATTR drv_touch_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
#if TOUCH_DRIVER > 0
    int16_t touchX, touchY;
    bool touched = drv_touchpad_getXY(&touchX, &touchY);
    if(touched && hasp_sleep_state != HASP_SLEEP_OFF) hasp_update_sleep_state(); // update Idle

    // Ignore first press?

    /*Save the state and save the pressed coordinate for cursor position */
    data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
    if(touched) {
        data->point.x = touchX;
        data->point.y = touchY;
    }
#endif

    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

void IRAM_ATTR drv_touch_loop()
{
#if TOUCH_DRIVER == 911
    GT911_loop();
#endif
}