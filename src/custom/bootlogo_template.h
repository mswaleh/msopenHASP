// Images can be converted to XBM format by using the online converter here:
// https://www.online-utility.org/image/convert/to/XBM

// The output must be pasted in a header file, renamed and adjusted to appear
// as a const unsigned char array in PROGMEM (FLASH program memory).

// The xbm format adds padding to pixel rows so they are a whole number of bytes
// In this example 93 pixel width means 96 bits = 12 bytes
// the 16 height then means array uses 12 x 16 = 192 bytes of FLASH
// The library ignores the padding bits when drawing the image on the display.

// The openHASP logo uses the MaterialDesign icons font, released under the OFL license

// Usage:
//    - Copy this file to src/custom/bootlogo.h
//    - Add #define HASP_CUSTOMIZE_BOOTLOGO to include/user_config_override.h

#ifndef HASP_BOOTLOGO_H
#define HASP_BOOTLOGO_H

// RGB array
#define logoBgColor {0,128,128}
#define logoFgColor {255,255,255}

#define logoWidth 93
#define logoHeight 16

// Image is stored in the array below, also update the width and height accordingly
PROGMEM const unsigned char logoImage[] = {
    0x7C, 0xF0, 0x07, 0xFF, 0x71, 0x1C, 0xC7, 0xC1, 0x07, 0xFC, 0xF1, 0x07, 0xFE, 0xF0, 0x0F, 0xFF, 0xF1, 0x1C,
    0xC7, 0xE1, 0x0F, 0xFE, 0xF1, 0x0F, 0xFF, 0xF1, 0x1F, 0xFF, 0xF1, 0x1C, 0xC7, 0xF1, 0x1F, 0xFF, 0xF1, 0x1F,
    0xC7, 0x71, 0x1C, 0x07, 0xF0, 0x1C, 0xC7, 0x71, 0x1C, 0x07, 0x70, 0x1C, 0xC7, 0x71, 0x1C, 0x07, 0xF0, 0x1D,
    0xC7, 0x71, 0x1C, 0x07, 0x70, 0x1C, 0xC7, 0x71, 0x1C, 0x07, 0xF0, 0x1D, 0xC7, 0x71, 0x1C, 0x07, 0x70, 0x1C,
    0xC7, 0x71, 0x1C, 0x07, 0xF0, 0x1F, 0xC7, 0x71, 0x1C, 0x07, 0x70, 0x1C, 0xC7, 0xF1, 0x1F, 0xFF, 0xF1, 0x1F,
    0xFF, 0xF1, 0x1F, 0xFF, 0xF0, 0x1F, 0xC7, 0xF1, 0x0F, 0xFF, 0xF1, 0x1F, 0xFF, 0xF1, 0x1F, 0xFE, 0xF1, 0x0F,
    0xC7, 0xF1, 0x07, 0xFF, 0xF1, 0x1F, 0xFF, 0xF1, 0x1F, 0xFC, 0xF1, 0x07, 0xC7, 0x71, 0x00, 0x07, 0x70, 0x1F,
    0xC7, 0x71, 0x1C, 0xC0, 0x71, 0x00, 0xC7, 0x71, 0x00, 0x07, 0x70, 0x1F, 0xC7, 0x71, 0x1C, 0xC0, 0x71, 0x00,
    0xC7, 0x71, 0x00, 0x07, 0x70, 0x1E, 0xC7, 0x71, 0x1C, 0xC0, 0x71, 0x00, 0xFF, 0x71, 0x00, 0xFF, 0x71, 0x1E,
    0xC7, 0x71, 0x1C, 0xFF, 0x71, 0x00, 0xFE, 0x70, 0x00, 0xFF, 0x71, 0x1E, 0xC7, 0x71, 0x1C, 0xFF, 0x71, 0x00,
    0x7C, 0x70, 0x00, 0xFF, 0x71, 0x1C, 0xC7, 0x71, 0x1C, 0xFF, 0x70, 0x00,
};

#endif // HASP_BOOTLOGO_H