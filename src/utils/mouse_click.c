/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** mouse_click
*/

#include "gui.h"
#include "handlers.h"
#include "paint.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System.h>
#include <unistd.h>

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

void exec_clear(paint_t *paint)
{
    sfRectangleShape *clear = sfRectangleShape_create();
    sfRectangleShape_setSize(clear, (sfVector2f){1600, 900});
    sfRectangleShape_setFillColor(clear, sfWhite);
    sfRenderTexture_drawRectangleShape(paint->render, clear, NULL);
}

void exec_btn(paint_t *paint, int i)
{
    if (paint->gui->buttons[0]->state != BTN_CLICKED) return;
    if (i == 15) {
        exec_clear(paint);
    }
    if (i == 16) {
        if (!paint->open_path) {
            write(2, "No file to open\n", 16); return;
        }
        sfTexture *texture = sfTexture_createFromFile(paint->open_path, NULL);
        sfSprite *sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, (sfVector2f){0, 0});
        sfRenderTexture_drawSprite(paint->render, sprite, NULL);
    } else {
        const sfTexture *texture = sfRenderTexture_getTexture(paint->render);
        sfImage *image = sfTexture_copyToImage(texture);
        sfImage_saveToFile(image, paint->save_path);
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
    if (mouse_pos.x >= new_btn_pos.x && mouse_pos.x <= new_btn_pos.x +
    new_btn_size.x && mouse_pos.y >= new_btn_pos.y &&
    mouse_pos.y <= new_btn_pos.y + new_btn_size.y) {
        if (i > 14) {
            exec_btn(paint, i); return;
        }
        paint->gui->buttons[i]->state = BTN_CLICKED; checker_state(paint, i);
    }
}
