/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

void stucked_crates(fct_struct_t *fstruct)
{
    fstruct->face_left_right_touch = 0;
    fstruct->face_up_down_touch = 0;
    for (int i = 0; i < fstruct->height; i++) {
        for (int j = 0; j < my_strlen(fstruct->map[i]); j++) {
            faces_contact_detect(fstruct, i, j);
            fstruct->face_left_right_touch = 0;
            fstruct->face_up_down_touch = 0;
        }
    }
}

void faces_contact_detect(fct_struct_t *fstruct, int i, int j)
{
    if (fstruct->map[i][j] == 'X') {
        fstruct->nb_crates++;
        if (fstruct->map[i + 1][j] == '#' ||
            fstruct->map[i + 1][j] == 'X')
            fstruct->face_left_right_touch = 1;
        if (fstruct->map[i - 1][j] == '#' ||
            fstruct->map[i - 1][j] == 'X')
            fstruct->face_left_right_touch = 1;
        if (fstruct->map[i][j + 1] == '#' ||
            fstruct->map[i][j + 1] == 'X')
            fstruct->face_up_down_touch = 1;
        if (fstruct->map[i][j - 1] == '#' ||
            fstruct->map[i][j - 1] == 'X')
            fstruct->face_up_down_touch = 1;
        if (fstruct->face_left_right_touch == 1 &&
            fstruct->face_up_down_touch == 1)
            fstruct->blocked_crates++;
    }
}

void struct_crates_init(fct_struct_t *fstruct)
{
    fstruct->blocked_crates = 0;
    fstruct->nb_crates = 0;
}
