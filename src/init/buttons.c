/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** buttons
*/

#include "constants.h"
#include "gui.h"
#include "init.h"
#include "paint.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
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

void check_btns(paint_t *paint, sfRectangleShape *btns[], int i)
{
    paint->gui->buttons[i] = malloc(sizeof(button_t));
    paint->gui->buttons[i]->btn = btns[i];
    paint->gui->buttons[i]->state = (i == 1 || i == 3) ?
    BTN_CLICKED : BTN_NONE;
}

sfRectangleShape **get_btns(void)
{
    sfRectangleShape **btns = malloc(sizeof(sfRectangleShape *) * 6);
    btns[0] = sfRectangleShape_create();
    btns[1] = sfRectangleShape_create();
    btns[2] = sfRectangleShape_create();
    btns[3] = sfRectangleShape_create();
    btns[4] = sfRectangleShape_create();
    btns[5] = sfRectangleShape_create();
    return (btns);
}

return_code_t init_buttons(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);
    int i;
    sfVector2f sizes[] = {{50, 30}, {50, 30},
    {50, 30}, {75, 75}, {75, 75}, {75, 75}};
    sfVector2f positions[] = {{0, 0}, {51, 0}, {102, 0},
    {20, 45}, {110, 45}, {200, 45}};
    sfColor color = sfColor_fromRGB(220, 220, 220);
    sfColor outlineColor = sfColor_fromRGB(230, 230, 230);
    double outlineThickness = 2; sfRectangleShape **btns = get_btns();
    for (i = 0; i < 6; i++) {
        sfRectangleShape_setSize(btns[i], sizes[i]);
        sfRectangleShape_setFillColor(btns[i], color);
        sfRectangleShape_setPosition(btns[i], positions[i]);
        if (i >= 3) {
            sfRectangleShape_setOutlineColor(btns[i], outlineColor);
            sfRectangleShape_setOutlineThickness(btns[i], outlineThickness);
        }
        check_btns(paint, btns, i);
    }
    create_color_buttons(paint); return (CRETURN_SUCCESS);
}
