

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4A4A
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    JJKeyboards
#define PRODUCT         zweimalzwei
#define DESCRIPTION     zweimalzwei Test Board

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 2

/* pin-out */
#define MATRIX_ROW_PINS { F0, F1 }
#define MATRIX_COL_PINS { F4, F5 }
#define UNUSED_PINS

#define USB_MAX_POWER_CONSUMPTION 250


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


#endif
