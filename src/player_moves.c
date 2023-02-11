/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

void player_move(fct_struct_t *fstruct)
{
    key_forward(fstruct);
    key_backard(fstruct);
    key_left(fstruct);
    key_right(fstruct);
}

void player_move_forward(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_y = fstruct->player_y - 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
}

void player_move_backward(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_y = fstruct->player_y + 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
}

void player_move_left(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_x = fstruct->player_x - 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
}

void player_move_right(fct_struct_t *fstruct)
{
    fstruct->map[fstruct->player_y][fstruct->player_x] = ' ';
    fstruct->player_x = fstruct->player_x + 1;
    fstruct->map[fstruct->player_y][fstruct->player_x] = 'P';
}
