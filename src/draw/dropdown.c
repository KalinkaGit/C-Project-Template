/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** dropdown
*/

#include "constants.h"
#include "paint.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Text.h>

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

return_code_t draw_help(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);

    sfText *help = sfText_create();
    sfText_setString(help, "How to use: DRAW\nLogin:");
    sfText_setFont(help, paint->gui->font);
    sfText_setColor(help, sfColor_fromRGB(255, 255, 255));
    sfText_setCharacterSize(help, 30);
    sfText_setPosition(help, (sfVector2f){10, 40});
    sfRenderWindow_drawText(paint->window->win, help, NULL);
    sfText_destroy(help);
    sfText *login = sfText_create();
    sfText_setString(login, paint->login);
    sfText_setFont(login, paint->gui->font);
    sfText_setColor(login, sfColor_fromRGB(255, 255, 255));
    sfText_setCharacterSize(login, 30);
    sfText_setPosition(login, (sfVector2f){100, 76});
    sfRenderWindow_drawText(paint->window->win, login, NULL);
    sfText_destroy(login);
    return (CRETURN_SUCCESS);
}
