/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** paint
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics/Types.h>
#include <stdlib.h>

/* LOCAL INCLUDES */
#include "constants.h"
#include "paint.h"
#include "init.h"

void create_plus_minus_buttons(paint_t *paint)
{
    sfRectangleShape *plus = sfRectangleShape_create();
    sfRectangleShape *minus = sfRectangleShape_create();

    sfRectangleShape_setSize(plus, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(plus, sfWhite);
    sfRectangleShape_setPosition(plus, (sfVector2f){300, 100});
    sfRectangleShape_setOutlineColor(plus, sfColor_fromRGB(230, 230, 230));
    sfRectangleShape_setOutlineThickness(plus, 1);
    sfRectangleShape_setSize(minus, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(minus, sfWhite);
    sfRectangleShape_setPosition(minus, (sfVector2f){325, 100});
    sfRectangleShape_setOutlineColor(minus, sfColor_fromRGB(230, 230, 230));
    sfRectangleShape_setOutlineThickness(minus, 1);
    paint->gui->buttons[12] = malloc(sizeof(button_t));
    paint->gui->buttons[13] = malloc(sizeof(button_t));
    paint->gui->buttons[12]->btn = plus;
    paint->gui->buttons[13]->btn = minus;
    paint->gui->buttons[12]->state = BTN_NONE;
    paint->gui->buttons[13]->state = BTN_NONE;
}

return_code_t init_paint_gui(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);
    if (init_buttons(paint) == CRETURN_FAILURE) return (CRETURN_FAILURE);
    paint->gui->textures = malloc(sizeof(sfTexture *) * 7);
    if (!paint->gui->textures) return (CRETURN_FAILURE);
    if (init_textures(paint) == CRETURN_FAILURE) return (CRETURN_FAILURE);
    paint->render = sfRenderTexture_create(1500, 600, sfFalse);
    if (!paint->render) return (CRETURN_FAILURE);
    sfRenderTexture_clear(paint->render, sfColor_fromRGB(255, 255, 255));
    create_plus_minus_buttons(paint);
    return (CRETURN_SUCCESS);
}

paint_t *init_paint(void)
{
    paint_t *paint = malloc(sizeof(paint_t));
    if (!paint) return (NULL);
    paint->tool = TOOL_BRUSH;
    paint->color = sfBlack;
    paint->draw_zone = sfSprite_create();
    paint->size = 5;
    sfSprite_setOrigin(paint->draw_zone, (sfVector2f){0, 0});
    paint->window = malloc(sizeof(window_t));
    if (!paint->window) return (NULL);
    paint->window->win = sfRenderWindow_create((sfVideoMode){1600, 800, 32},
        "My Paint", sfClose | sfResize, NULL);
    if (!paint->window->win) return (NULL);
    paint->window->size = (sfVector2f){1600, 800};
    paint->gui = malloc(sizeof(gui_t));
    if (!paint->gui) return (NULL);
    paint->gui->buttons = malloc(sizeof(button_t *) * 15);
    if (!paint->gui->buttons) return (NULL);
    paint->gui->font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (init_paint_gui(paint) == CRETURN_FAILURE) return (NULL);
    return (paint);
}
