/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** paint
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

/* LOCAL INCLUDES */
#include "constants.h"
#include "gui.h"
#include "paint.h"
#include "handlers.h"

return_code_t draw_file_dropdown(paint_t *paint);

return_code_t draw_on_texture(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(
    paint->window->win);
    sfFloatRect zone_bounds = sfSprite_getGlobalBounds(paint->draw_zone);
    mouse_pos.x -= zone_bounds.left;
    mouse_pos.y -= zone_bounds.top;
    mouse_pos.y = zone_bounds.height - mouse_pos.y;
    if (mouse_pos.x >= 0 && mouse_pos.x <= zone_bounds.width
    && mouse_pos.y >= 0 && mouse_pos.y <= zone_bounds.height) {
        sfCircleShape *circle = sfCircleShape_create();
        sfCircleShape_setRadius(circle, paint->size);
        sfCircleShape_setFillColor(circle,
        paint->tool == TOOL_BRUSH ? paint->color : sfWhite);
        sfCircleShape_setPosition(circle,
        (sfVector2f){mouse_pos.x, mouse_pos.y});
        sfRenderTexture_drawCircleShape(paint->render,
        circle, NULL);
        sfCircleShape_destroy(circle);
    }
    return (CRETURN_SUCCESS);
}

return_code_t check_drawing(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (draw_on_texture(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }
    return (CRETURN_SUCCESS);
}

return_code_t draw_file_menu(paint_t *paint)
{
    if (!paint)
        return (CRETURN_FAILURE);

    if (paint->gui->buttons[0]->state == BTN_CLICKED) {
        sfRectangleShape *file_menu = sfRectangleShape_create();
        sfRectangleShape_setSize(file_menu, (sfVector2f){100, 90});
        sfRectangleShape_setFillColor(file_menu, sfWhite);
        sfRectangleShape_setPosition(file_menu, (sfVector2f){0, 30});
        sfRenderWindow_drawRectangleShape(paint->window->win, file_menu, NULL);
        sfRectangleShape_destroy(file_menu);
        if (draw_file_dropdown(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
        for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(paint->window->win,
        paint->gui->texts[i], NULL);
    }

    return (CRETURN_SUCCESS);
}

return_code_t paint_loop(paint_t *paint)
{
    while (sfRenderWindow_pollEvent(paint->window->win,
    &paint->window->event)) {
        if (handle_events(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }

    sfRenderWindow_clear(paint->window->win, sfColor_fromRGB(222, 222, 222));
    if (draw_dropdown(paint) == CRETURN_FAILURE)
        return (CRETURN_FAILURE);
    if (draw_gui(paint) == CRETURN_FAILURE)
        return (CRETURN_FAILURE);
    if (draw_file_menu(paint) == CRETURN_FAILURE)
        return (CRETURN_FAILURE);
    if (check_drawing(paint) == CRETURN_FAILURE)
        return (CRETURN_FAILURE);
    sfRenderWindow_display(paint->window->win);

    return (CRETURN_SUCCESS);
}

return_code_t start_paint(paint_t *paint)
{
    if (!paint)
        return (CRETURN_FAILURE);

    while (sfRenderWindow_isOpen(paint->window->win)) {
        if (paint_loop(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }

    return (CRETURN_SUCCESS);
}
