/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** menu
*/

/* LOCAL INCLUDES */
#include "constants.h"
#include "paint.h"

return_code_t draw_edit_dropdown(paint_t *paint);
return_code_t draw_help(paint_t *paint);

return_code_t draw_main_buttons(paint_t *paint, int i)
{
    if (!paint)
        return (CRETURN_FAILURE);
    sfRenderWindow_drawRectangleShape(paint->window->win,
    paint->gui->buttons[i]->btn, NULL);
    if (paint->gui->buttons[i]->state == BTN_CLICKED) {
        if (i == 0) {
            sfRectangleShape_setFillColor(paint->gui->buttons[i]->btn,
            sfColor_fromRGB(200, 200, 200));
        } else {
            sfRectangleShape_setFillColor(paint->gui->buttons[i]->btn,
            sfColor_fromRGB(48, 190, 255));
        }
    } else if (paint->gui->buttons[i]->state == BTN_HOVER) {
        sfRectangleShape_setFillColor(paint->gui->buttons[i]->btn,
        sfColor_fromRGB(220, 220, 220));
    } else {
        sfRectangleShape_setFillColor(paint->gui->buttons[i]->btn,
        sfColor_fromRGB(255, 255, 255));
    }
    return (CRETURN_SUCCESS);
}

return_code_t draw_file_dropdown(paint_t *paint)
{
    if (!paint)
        return (CRETURN_FAILURE);

    for (int i = 15; i < 18; i++) {
        sfRenderWindow_drawRectangleShape(paint->window->win,
        paint->gui->buttons[i]->btn, NULL);
        sfRectangleShape_setFillColor(paint->gui->buttons[i]->btn,
        paint->gui->buttons[i]->state == BTN_CLICKED ?
        sfColor_fromRGB(48, 190, 255) :
        paint->gui->buttons[i]->state == BTN_HOVER ?
        sfColor_fromRGB(220, 220, 220) :
        sfColor_fromRGB(255, 255, 255));
    }
    return (CRETURN_SUCCESS);
}

return_code_t draw_buttons(paint_t *paint)
{
    if (!paint)
        return (CRETURN_FAILURE);

    for (int i = 0; i < 3; i++) {
        if (draw_main_buttons(paint, i) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }

    if (paint->gui->buttons[1]->state == BTN_CLICKED) {
        if (draw_edit_dropdown(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }

    if (paint->gui->buttons[2]->state == BTN_CLICKED) {
        if (draw_help(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }

    return (CRETURN_SUCCESS);
}

void draw_texts(paint_t *paint)
{
    const char* texts[] = {"File", "Edit", "Help"};
    const sfVector2f positions[] = {{8, 4}, {57, 4}, {106, 4}};

    for (int i = 0; i < 3; i++) {
        sfText *text = sfText_create();
        sfText_setString(text, texts[i]);
        sfText_setFont(text, paint->gui->font);
        sfText_setCharacterSize(text, 20);
        sfText_setPosition(text, positions[i]);
        sfText_setColor(text, sfBlack);
        sfRenderWindow_drawText(paint->window->win, text, NULL);
        sfText_destroy(text);
    }
}

return_code_t draw_gui(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);

    sfRectangleShape *navbar = sfRectangleShape_create();
    sfRectangleShape_setSize(navbar, (sfVector2f){1600, 30});
    sfRectangleShape_setFillColor(navbar, sfColor_fromRGB(200, 200, 200));
    sfRectangleShape_setPosition(navbar, (sfVector2f){0, 0});
    sfRenderWindow_drawRectangleShape(paint->window->win, navbar, NULL);
    sfRectangleShape_destroy(navbar);

    sfSprite_setTexture(paint->draw_zone,
    sfRenderTexture_getTexture(paint->render), sfTrue);
    sfSprite_setPosition(paint->draw_zone, (sfVector2f){50, 165});
    sfRenderWindow_drawSprite(paint->window->win, paint->draw_zone, NULL);

    draw_buttons(paint);
    draw_texts(paint);

    return (CRETURN_SUCCESS);
}
