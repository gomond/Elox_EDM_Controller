// 4.23.0 0x0c58f2f9
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_alternate_theme_images_widgets_togglebutton_medium_rounded_off_light[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_MEDIUM_ROUNDED_OFF_LIGHT_ID = 0, Size: 110x50 pixels
extern const unsigned char image_alternate_theme_images_widgets_togglebutton_medium_rounded_on_normal[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_MEDIUM_ROUNDED_ON_NORMAL_ID = 1, Size: 110x50 pixels
extern const unsigned char image_blue_buttons_round_large[]; // BITMAP_BLUE_BUTTONS_ROUND_LARGE_ID = 2, Size: 360x60 pixels
extern const unsigned char image_blue_buttons_round_large_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_LARGE_PRESSED_ID = 3, Size: 360x60 pixels
extern const unsigned char image_blue_slider_horizontal_large_indicators_slider_round_nob[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_INDICATORS_SLIDER_ROUND_NOB_ID = 4, Size: 58x58 pixels
extern const unsigned char image_blue_slider_horizontal_large_slider_round_back[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_BACK_ID = 5, Size: 672x15 pixels
extern const unsigned char image_blue_slider_horizontal_large_slider_round_fill[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_FILL_ID = 6, Size: 672x15 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_alternate_theme_images_widgets_togglebutton_medium_rounded_off_light, 0, 110, 50, 10, 9, 43, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 32, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_togglebutton_medium_rounded_on_normal, 0, 110, 50, 57, 9, 43, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 32, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_large, 0, 360, 60, 22, 5, 316, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 48, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_large_pressed, 0, 360, 60, 22, 5, 316, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 48, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_slider_horizontal_large_indicators_slider_round_nob, 0, 58, 58, 10, 9, 38, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 38, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_slider_horizontal_large_slider_round_back, 0, 672, 15, 7, 1, 658, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_slider_horizontal_large_slider_round_fill, 0, 672, 15, 7, 0, 658, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 14, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase