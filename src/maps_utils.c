/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

int content_map_checker(fct_struct_t *fstruct)
{
    for (int i = 0; i < fstruct->height; i++) {
        if (map_char_detector(fstruct, i) == 84)
            exit(84);
    }
    return 0;
}

int map_char_detector(fct_struct_t *fstruct, int i)
{
    for (int j = 0; j < my_strlen(fstruct->map[i]); j++) {
        if (fstruct->map[i][j] != ' ' && fstruct->map[i][j] != '#' &&
            fstruct->map[i][j] != 'P' && fstruct->map[i][j] != 'X' &&
            fstruct->map[i][j] != 'O')
            return 84;
    }
    return 0;
}

void load_map(fct_struct_t *fstruct)
{
    char *map_file;
    char **map;

    map_file = malloc(sizeof(char) * 4096);
    read(fstruct->fd, map_file, 4096);
    fstruct->height = count_line(map_file, fstruct);
    close(fstruct->fd);
    map = malloc(sizeof(char*) * fstruct->height);
    fstruct->map = map_to_array(fstruct, map_file, map);
    free(map_file);
}

char** map_to_array(fct_struct_t *fstruct, char *map_file, char **map)
{
    int index_x = 0;
    int index_y = 0;
    int index = 0;

    for (int i = 0; i < fstruct->height; i++) {
        map[i] = malloc(sizeof(char) * 4096);
    }
    while (map_file[index] != '\0') {
        if (map_file[index] != '\n') {
            map[index_y][index_x] = map_file[index];
            index_x++;
            index++;
        }
        if (map_file[index] == '\n') {
            index++;
            index_x = 0;
            index_y++;
        }
    }
    return map;
}

int count_line(char *input_map, fct_struct_t *fstruct)
{
    int len = my_strlen(input_map);
    int count = 0;

    fstruct->file_len = len;
    for (int i = 0; i < len; i++) {
        if (input_map[i] == '\n')
            count++;
    }
    return count;
}
