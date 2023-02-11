/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

void player_crate_move_forward(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_y = fstruct->player_y - 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
    fstruct->map[fstruct->player_y - 1][fstruct->player_x] = 'X';
}

void player_crate_move_backward(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_y = fstruct->player_y + 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
    fstruct->map[fstruct->player_y + 1][fstruct->player_x] = 'X';
}

void player_crate_move_left(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_x = fstruct->player_x - 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
    fstruct->map[fstruct->player_y][fstruct->player_x - 1] = 'X';
}

void player_crate_move_right(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_x = fstruct->player_x + 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
    fstruct->map[fstruct->player_y][fstruct->player_x + 1] = 'X';
}
