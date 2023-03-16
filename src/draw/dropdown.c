/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** dropdown
*/

#include "constants.h"
#include "paint.h"
#include <SFML/Graphics/Color.h>

return_code_t draw_dropdown(paint_t *paint)
{
    if (!paint)
        return (CRETURN_FAILURE);

    sfRectangleShape *drop = sfRectangleShape_create();
    sfRectangleShape_setPosition(drop, (sfVector2f){0, 30});
    sfRectangleShape_setSize(drop, (sfVector2f){1600, 100});
    sfRectangleShape_setFillColor(drop, sfColor_fromRGB(48, 190, 255));
    sfRenderWindow_drawRectangleShape(paint->window->win, drop, NULL);
    sfRectangleShape_destroy(drop);

    return (CRETURN_SUCCESS);
}

return_code_t draw_edit_dropdown(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);
    for (int i = 3; i < 14; i++) {
        sfRenderWindow_drawRectangleShape(paint->window->win,
        paint->gui->buttons[i]->btn, NULL);
        if (i < 6)
            sfRectangleShape_setFillColor(paint->gui->buttons[i]->btn,
    paint->gui->buttons[i]->state == BTN_CLICKED ?
            sfColor_fromRGB(48, 190, 255) :
            paint->gui->buttons[i]->state == BTN_HOVER ?
            sfColor_fromRGB(220, 220, 220) :
            sfColor_fromRGB(255, 255, 255));
        else
            sfRectangleShape_setOutlineColor(paint->gui->buttons[i]->btn,
            paint->gui->buttons[i]->state == BTN_CLICKED ?
            sfColor_fromRGB(48, 190, 255) :
            paint->gui->buttons[i]->state == BTN_HOVER ?
            sfColor_fromRGB(220, 220, 220) :
            sfColor_fromRGB(255, 255, 255));
    }
    draw_edit_style(paint); return (CRETURN_SUCCESS);
}
