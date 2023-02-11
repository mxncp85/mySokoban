/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

void key_move_crate_forward(fct_struct_t *fstruct)
{
    if (fstruct->map[fstruct->player_y - 2][fstruct->player_x] != '#'
        && fstruct->map[fstruct->player_y - 2][fstruct->player_x] != 'X')
        player_crate_move_forward(fstruct);
    return;
}

void key_move_crate_backward(fct_struct_t *fstruct)
{
    if (fstruct->map[fstruct->player_y + 2][fstruct->player_x] != '#'
        && fstruct->map[fstruct->player_y + 2][fstruct->player_x] != 'X')
        player_crate_move_backward(fstruct);
    return;
}

void key_move_crate_left(fct_struct_t *fstruct)
{
    if (fstruct->map[fstruct->player_y][fstruct->player_x - 2] != '#'
        && fstruct->map[fstruct->player_y][fstruct->player_x - 2] != 'X')
        player_crate_move_left(fstruct);
    return;
}

void key_move_crate_right(fct_struct_t *fstruct)
{
    if (fstruct->map[fstruct->player_y][fstruct->player_x + 2] != '#'
        && fstruct->map[fstruct->player_y][fstruct->player_x + 2] != 'X')
        player_crate_move_right(fstruct);
    return;
}
