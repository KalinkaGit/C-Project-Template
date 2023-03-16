/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    /* SYSTEM INCLUDES */
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>

    typedef struct {
        sfRenderWindow *win;
        sfVector2f size;
        sfEvent event;
    } window_t;

#endif /* !WINDOW_H_ */
