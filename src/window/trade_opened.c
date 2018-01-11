#include "trade_opened.h"

#include "empire/city.h"
#include "graphics/graphics.h"
#include "graphics/image_button.h"
#include "graphics/lang_text.h"
#include "graphics/panel.h"
#include "graphics/window.h"
#include "window/empire.h"

#include "UI/Advisors.h"

static void button_advisor(int advisor, int param2);
static void button_close(int param1, int param2);

static image_button image_buttons[] = {
    {92, 248, 28, 28, IB_NORMAL, 199, 12, button_advisor, button_none, ADVISOR_TRADE, 0, 1},
    {522, 252, 24, 24, IB_NORMAL, 134, 4, button_close, button_none, 0, 0, 1},
};

static int selected_city;

static void draw_background()
{
    graphics_in_dialog();

    outer_panel_draw(80, 64, 30, 14);
    lang_text_draw_centered(142, 0, 80, 80, 480, FONT_LARGE_BLACK);
    if (empire_city_get(selected_city)->is_sea_trade) {
        lang_text_draw_multiline(142, 1, 112, 120, 416, FONT_NORMAL_BLACK);
        lang_text_draw_multiline(142, 3, 112, 184, 416, FONT_NORMAL_BLACK);
    } else {
        lang_text_draw_multiline(142, 1, 112, 152, 416, FONT_NORMAL_BLACK);
    }
    lang_text_draw(142, 2, 128, 256, FONT_NORMAL_BLACK);

    graphics_reset_dialog();
}

static void draw_foreground()
{
    graphics_in_dialog();
    image_buttons_draw(0, 0, image_buttons, 2);
    graphics_reset_dialog();
}

static void handle_mouse(const mouse *m)
{
    image_buttons_handle_mouse(mouse_in_dialog(m), 0, 0, image_buttons, 2, 0);
}

static void button_advisor(int advisor, int param2)
{
    UI_Advisors_goToFromMessage(advisor);
}

static void button_close(int param1, int param2)
{
    window_empire_show();
}

void window_trade_opened_show(int city)
{
    window_type window = {
        Window_TradeOpenedDialog,
        draw_background,
        draw_foreground,
        handle_mouse
    };
    selected_city = city;
    window_show(&window);
}