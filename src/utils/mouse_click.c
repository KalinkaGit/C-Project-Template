/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** mouse_click
*/

#include "gui.h"
#include "handlers.h"

void check_btn(paint_t *paint, sfVector2i mouse_pos, int i,
sfVector2f window_size)
{
    btn_state_t state = paint->gui->buttons[i]->state;
    sfVector2f btn_pos = sfRectangleShape_getPosition(
    paint->gui->buttons[i]->btn);
    sfVector2f btn_size = sfRectangleShape_getSize(paint->gui->buttons[i]->btn);
    sfVector2f new_btn_pos = {
        btn_pos.x * window_size.x / 1600,
        btn_pos.y * window_size.y / 900
    };
    sfVector2f new_btn_size = {
        btn_size.x * window_size.x / 1600,
        btn_size.y * window_size.y / 900
    };
    if (mouse_pos.x >= new_btn_pos.x
    && mouse_pos.x <= new_btn_pos.x + new_btn_size.x &&
    mouse_pos.y >= new_btn_pos.y
    && mouse_pos.y <= new_btn_pos.y + new_btn_size.y) {
        if (state == BTN_NONE) state = BTN_HOVER;
    } else {
        if (state == BTN_HOVER) state = BTN_NONE;
    }
}

void mouse_click(paint_t *paint, sfVector2i mouse_pos, int i,
sfVector2f window_size)
{
    sfVector2f btn_pos = sfRectangleShape_getPosition(
    paint->gui->buttons[i]->btn);
    sfVector2f btn_size = sfRectangleShape_getSize(
    paint->gui->buttons[i]->btn);
    sfVector2f new_btn_pos = {
        btn_pos.x * window_size.x / 1600,
        btn_pos.y * window_size.y / 900
    };
    sfVector2f new_btn_size = {
        btn_size.x * window_size.x / 1600,
        btn_size.y * window_size.y / 900
    };
    if (mouse_pos.x >= new_btn_pos.x &&
    mouse_pos.x <= new_btn_pos.x + new_btn_size.x &&
    mouse_pos.y >= new_btn_pos.y &&
    mouse_pos.y <= new_btn_pos.y + new_btn_size.y) {
        paint->gui->buttons[i]->state = BTN_CLICKED;
        checker_state(paint, i);
    }
}
