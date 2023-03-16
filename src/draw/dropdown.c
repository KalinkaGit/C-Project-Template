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
