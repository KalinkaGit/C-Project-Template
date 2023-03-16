/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** events
*/

#include "constants.h"
#include "handlers.h"
#include "paint.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>

void mouse_click(paint_t *paint, sfVector2i mouse_pos, int i,
sfVector2f window_size);
void check_btn(paint_t *paint, sfVector2i mouse_pos, int i,
sfVector2f window_size);

return_code_t handle_mouse_click(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(
        paint->window->win);
    sfVector2f window_size = paint->window->size;
    for (int i = 0; i < 14; i++) {
        mouse_click(paint, mouse_pos, i, window_size);
    }
    paint->gui->buttons[0]->state = BTN_NONE;
    return (CRETURN_SUCCESS);
}

return_code_t handle_resize(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);

    sfVector2u size = sfRenderWindow_getSize(paint->window->win);
    paint->window->size = (sfVector2f){size.x, size.y};
    return (CRETURN_SUCCESS);
}

return_code_t check_over_btn(paint_t *paint, sfVector2i mouse_pos)
{
    if (!paint) return (CRETURN_FAILURE);

    sfVector2f window_size = paint->window->size;
    for (int i = 0; i < 12; i++) {
        check_btn(paint, mouse_pos, i, window_size);
    }

    return (CRETURN_SUCCESS);
}

return_code_t handle_mouse_move(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);

    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(
        paint->window->win);

    if (check_over_btn(paint, mouse_pos) == CRETURN_FAILURE)
        return (CRETURN_FAILURE);

    return (CRETURN_SUCCESS);
}

return_code_t handle_events(paint_t *paint)
{
    if (!paint) return (CRETURN_FAILURE);

    if (paint->window->event.type == sfEvtClosed)
        sfRenderWindow_close(paint->window->win);
    if (paint->window->event.type == sfEvtMouseButtonPressed) {
        if (handle_mouse_click(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }
    if (paint->window->event.type == sfEvtMouseMoved) {
        if (handle_mouse_move(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }
    if (paint->window->event.type == sfEvtResized) {
        if (handle_resize(paint) == CRETURN_FAILURE)
            return (CRETURN_FAILURE);
    }

    return (CRETURN_SUCCESS);
}
