/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** style
*/

#include "paint.h"
#include <SFML/Graphics/Sprite.h>

void draw_textures(paint_t *paint)
{
    sfSprite *pencil = sfSprite_create();
    sfSprite_setTexture(pencil, paint->gui->textures[0], sfTrue);
    sfSprite_setPosition(pencil, (sfVector2f){34, 55});
    sfSprite_setScale(pencil, (sfVector2f){0.1, 0.1});
    sfRenderWindow_drawSprite(paint->window->win, pencil, NULL);
    sfSprite_destroy(pencil);
    sfSprite *eraser = sfSprite_create();
    sfSprite_setTexture(eraser, paint->gui->textures[1], sfTrue);
    sfSprite_setPosition(eraser, (sfVector2f){120, 50});
    sfSprite_setScale(eraser, (sfVector2f){0.018, 0.018});
    sfRenderWindow_drawSprite(paint->window->win, eraser, NULL);
    sfSprite_destroy(eraser);
    sfSprite *pad = sfSprite_create();
    sfSprite_setTexture(pad, paint->gui->textures[2], sfTrue);
    sfSprite_setPosition(pad, (sfVector2f){195, 40});
    sfSprite_setScale(pad, (sfVector2f){0.15, 0.15});
    sfRenderWindow_drawSprite(paint->window->win, pad, NULL);
    sfSprite_destroy(pad);
}

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

    draw_textures(paint);
}
