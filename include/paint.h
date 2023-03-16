/*
** EPITECH PROJECT, 2023
** my_paint_project
** File description:
** paint
*/

#ifndef PAINT_H_
    #define PAINT_H_

    /* SYSTEM INCLUDES */
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Types.h>

    /* LOCAL INCLUDES */
    #include "window.h"
    #include "gui.h"
    #include "constants.h"

    typedef enum {
        TOOL_BRUSH = 0,
        TOOL_ERASER = 1,
        TOOL_PAD = 2
    } tool_t;

    typedef struct {
        sfRectangleShape *rect;
        sfColor color;
    } color_btn_t;

    typedef struct {
        window_t *window;
        gui_t *gui;
        sfRenderTexture *render;
        sfSprite *draw_zone;
        tool_t tool;
        sfColor color;
        int size;
    } paint_t;

    /**
     * @brief Draw the main dropdown menu.
     *
     * @param paint Paint structure.
     * @return return_code_t 0 if drawing was successful, -1 otherwise.
     */
    return_code_t draw_dropdown(paint_t *paint);

    /**
     * @brief Draw the main GUI.
     *
     * @param paint Paint structure.
     * @return return_code_t 0 if drawing was successful, -1 otherwise.
     */
    return_code_t draw_gui(paint_t *paint);

    void draw_edit_style(paint_t *paint);

    void checker_state(paint_t *paint, int i);

    return_code_t start_paint(paint_t *paint);

#endif /* !PAINT_H_ */
