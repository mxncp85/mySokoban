/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

void key_forward(fct_struct_t *fstruct)
{
    if (fstruct->key_entry == KEY_UP) {
        if (fstruct->map[fstruct->player_y - 1][fstruct->player_x] == 'X') {
            key_move_crate_forward(fstruct);
            return;
        }
        if (fstruct->map[fstruct->player_y - 1][fstruct->player_x] != '#') {
            player_move_forward(fstruct);
            return;
        }
    }
}

void key_backard(fct_struct_t *fstruct)
{
    if (fstruct->key_entry == KEY_DOWN) {
        if (fstruct->map[fstruct->player_y + 1][fstruct->player_x] == 'X') {
            key_move_crate_backward(fstruct);
            return;
        }
        if (fstruct->map[fstruct->player_y + 1][fstruct->player_x] != '#') {
            player_move_backward(fstruct);
            return;
        }
    }
}

void key_left(fct_struct_t *fstruct)
{
    if (fstruct->key_entry == KEY_LEFT) {
        if (fstruct->map[fstruct->player_y][fstruct->player_x - 1] == 'X') {
            key_move_crate_left(fstruct);
            return;
        }
        if (fstruct->map[fstruct->player_y][fstruct->player_x - 1] != '#') {
            player_move_left(fstruct);
            return;
        }
    }
}

void key_right(fct_struct_t *fstruct)
{
    if (fstruct->key_entry == KEY_RIGHT) {
        if (fstruct->map[fstruct->player_y][fstruct->player_x + 1] == 'X') {
            key_move_crate_right(fstruct);
            return;
        }
        if (fstruct->map[fstruct->player_y][fstruct->player_x + 1] != '#') {
            player_move_right(fstruct);
            return;
        }
    }
}
