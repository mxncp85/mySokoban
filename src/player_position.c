/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

void player_pos_scan(fct_struct_t *fstruct)
{
    for (int i = 0; i < fstruct->height; i++) {
        for (int j = 0; j < my_strlen(fstruct->map[i]); j++) {
            player_position_save(fstruct, i, j);
        }
    }
}

void player_position_save(fct_struct_t *fstruct, int i, int j)
{
    if (fstruct->map[i][j] == 'P') {
        fstruct->player_y = i;
        fstruct->player_x = j;
    }
}
