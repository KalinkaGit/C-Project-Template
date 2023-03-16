/*
** EPITECH PROJECT, 2023
** paintv2
** File description:
** textures
*/

#include "constants.h"
#include "init.h"

return_code_t init_textures(paint_t *paint)
{
    if (!paint)
        return (CRETURN_FAILURE);

    paint->gui->textures[0] = sfTexture_createFromFile(
    "assets/images/pencil.png", NULL);
    paint->gui->textures[1] = sfTexture_createFromFile(
    "assets/images/eraser.png", NULL);
    paint->gui->textures[2] = sfTexture_createFromFile(
    "assets/images/pad.png", NULL);

    return (CRETURN_SUCCESS);
}
