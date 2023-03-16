/*
** EPITECH PROJECT, 2023
** my_paint_project
** File description:
** color_btns
*/

#include "paint.h"
#include <stdlib.h>

void init_color_btns(paint_t *paint, color_btn_t buttons[])
{
    for (int i = 0; i < 6; i++) {
        sfRectangleShape_setSize(buttons[i].rect, (sfVector2f){20, 20});
        sfRectangleShape_setFillColor(buttons[i].rect, buttons[i].color);
        sfRectangleShape_setPosition(buttons[i].rect,
        (sfVector2f){300 + 25 * i, 45});
        sfRectangleShape_setOutlineColor(buttons[i].rect,
        sfColor_fromRGB(230, 230, 230));
        sfRectangleShape_setOutlineThickness(buttons[i].rect, 1);
        paint->gui->buttons[6 + i] = malloc(sizeof(button_t));
        paint->gui->buttons[6 + i]->btn = buttons[i].rect;
        paint->gui->buttons[6 + i]->state = (i == 1) ? BTN_CLICKED : BTN_NONE;
        paint->gui->buttons[6 + i]->color = buttons[i].color;
    }
}

void create_color_buttons(paint_t *paint)
{
    color_btn_t buttons[] = {
        { .rect = sfRectangleShape_create(), .color = sfWhite },
        { .rect = sfRectangleShape_create(), .color = sfBlack },
        { .rect = sfRectangleShape_create(), .color = sfRed },
        { .rect = sfRectangleShape_create(), .color = sfGreen },
        { .rect = sfRectangleShape_create(), .color = sfBlue },
        { .rect = sfRectangleShape_create(),
        .color = sfColor_fromRGB(128, 0, 128) }
    };
    init_color_btns(paint, buttons);
}
