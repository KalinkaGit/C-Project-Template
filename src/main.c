/*
** EPITECH PROJECT, 2023
** PROJECT NAME
** File description:
** Main
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics/Font.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Window.h>

/* LOCAL INCLUDES */
#include "constants.h"
#include "handlers.h"
#include "paint.h"
#include "init.h"

return_code_t destroy_paint(paint_t *paint)
{
    if (!paint)
        return (CRETURN_FAILURE);

    for (int i = 0; i < 14; i++) {
        sfRectangleShape_destroy(paint->gui->buttons[i]->btn);
        free(paint->gui->buttons[i]);
    }
    free(paint->gui->buttons);
    sfFont_destroy(paint->gui->font);

    sfRenderWindow_destroy(paint->window->win);
    free(paint->window);
    free(paint->gui);
    sfRenderTexture_destroy(paint->render);
    sfSprite_destroy(paint->draw_zone);
    free(paint);

    return (CRETURN_SUCCESS);
}

int main(int argc, char *argv[], char *envp[])
{
    char *login;
    if (!(login = handle_errors(argc, envp)))
        return (CEXIT_FAILURE);

    paint_t *paint = init_paint(argc, argv);
    if (!paint) return (CEXIT_FAILURE);
    paint->login = login;

    if (start_paint(paint) == CRETURN_FAILURE)
        return (CEXIT_FAILURE);

    if (destroy_paint(paint) == CRETURN_FAILURE)
        return (CEXIT_FAILURE);

    return (CEXIT_SUCCESS);
}
