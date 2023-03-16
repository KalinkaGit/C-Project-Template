/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** gui
*/

#ifndef GUI_H_
    #define GUI_H_

    /* SYSTEM INCLUDES */
    #include <SFML/Config.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>

    typedef enum {
        BTN_NONE = 0,
        BTN_HOVER = 1,
        BTN_CLICKED = 2
    } btn_state_t;

    typedef struct {
        sfRectangleShape *btn;
        btn_state_t state;
        sfColor color;
    } button_t;

    typedef struct {
        button_t **buttons;
        sfTexture **textures;
        sfFont *font;
        sfText **texts;
    } gui_t;

#endif /* !GUI_H_ */
