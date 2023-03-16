/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** style
*/

#include "paint.h"

void draw_edit_style(paint_t *paint)
{
    sfText *text[] = {sfText_create(), sfText_create()};
    char *str[] = {"-", "+"};
    sfVector2f pos[] = {{305, 88}, {325, 90}};

    for (int i = 0; i < 2; i++) {
        sfText_setString(text[i], str[i]);
        sfText_setFont(text[i], paint->gui->font);
        sfText_setCharacterSize(text[i], 32);
        sfText_setColor(text[i], sfBlack);
        sfText_setPosition(text[i], pos[i]);
        sfRenderWindow_drawText(paint->window->win, text[i], NULL);
        sfText_destroy(text[i]);
    }

    sfSprite *pencil = sfSprite_create();
    sfSprite_setTexture(pencil, paint->gui->textures[0], sfTrue);
    sfSprite_setPosition(pencil, (sfVector2f){100, 20});
    sfSprite_setScale(pencil, (sfVector2f){0.1, 0.1});
    sfRenderWindow_drawSprite(paint->window->win, pencil, NULL);
    sfSprite_destroy(pencil);
}
