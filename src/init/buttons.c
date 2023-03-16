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

void create_color_buttons(paint_t *paint);

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

void draw_file_text(paint_t *paint, sfRectangleShape *btn, int i)
{
    sfText *text = sfText_create();
    sfText_setFont(text, paint->gui->font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, (i == 0) ? "New" : (i == 1) ? "Open" : "Save");
    sfVector2f pos = sfRectangleShape_getPosition(btn);
    sfVector2f size = sfRectangleShape_getSize(btn);
    sfText_setPosition(text, (sfVector2f){8,
    pos.y + size.y / 2 - 12});
    paint->gui->texts[i] = text;
}

void create_file_buttons(paint_t *paint)
{
    paint->gui->texts = malloc(sizeof(sfText *) * 3);
    sfRectangleShape **btns = get_btns();
    sfVector2f sizes[] = {{100, 30}, {100, 30}, {100, 30}};
    sfVector2f positions[] = {{0, 30}, {0, 60}, {0, 90}};
    for (int i = 15; i < 18; i++) {
        paint->gui->buttons[i] = malloc(sizeof(button_t));
        paint->gui->buttons[i]->btn = btns[i - 15];
        paint->gui->buttons[i]->state = BTN_NONE;
        sfRectangleShape_setSize(btns[i - 15], sizes[i - 15]);
        sfRectangleShape_setFillColor(btns[i - 15], sfGreen);
        sfRectangleShape_setPosition(btns[i - 15], positions[i - 15]);
        draw_file_text(paint, btns[i - 15], i - 15);
    }
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
        } check_btns(paint, btns, i);
    }
    create_file_buttons(paint);
    create_color_buttons(paint); return (CRETURN_SUCCESS);
}
