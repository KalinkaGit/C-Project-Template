/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** check_state
*/

#include "paint.h"

void checker_state_two(paint_t *paint, int i)
{
    if (i >= 6 && i <= 11) {
        for (int j = 6; j <= 11; j++)
            paint->gui->buttons[j]->state = BTN_NONE;
        paint->gui->buttons[i]->state = BTN_CLICKED;
        paint->color = paint->gui->buttons[i]->color;
    }
    if (i == 12) {
        paint->gui->buttons[13]->state = BTN_NONE;
        paint->gui->buttons[12]->state = BTN_CLICKED;
        if (paint->size > 1)
            paint->size--;
    }
    if (i == 13) {
        paint->gui->buttons[12]->state = BTN_NONE;
        paint->gui->buttons[13]->state = BTN_CLICKED;
        if (paint->size < 100)
            paint->size++;
    }
}

void checker_state(paint_t *paint, int i)
{
    if (i != 0)
        paint->gui->buttons[0]->state = BTN_NONE;
    if (i == 1)
        paint->gui->buttons[2]->state = BTN_NONE;
    else if (i == 2)
        paint->gui->buttons[1]->state = BTN_NONE;
    if (i == 3) {
        paint->gui->buttons[4]->state = BTN_NONE;
        paint->gui->buttons[5]->state = BTN_NONE;
        paint->tool = TOOL_BRUSH;
    }
    if (i == 4) {
        paint->gui->buttons[3]->state = BTN_NONE;
        paint->gui->buttons[5]->state = BTN_NONE; paint->tool = TOOL_ERASER;
    } else if (i == 5) {
        paint->gui->buttons[3]->state = BTN_NONE;
        paint->gui->buttons[4]->state = BTN_NONE;
        paint->tool = TOOL_PAD;
    }
    checker_state_two(paint, i);
}
