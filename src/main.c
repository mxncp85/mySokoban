/*
** EPITECH PROJECT, 2022
** bs sokoban
** File description:
** empty
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    fct_struct_t fstruct;

    fstruct.fd = open(av[1], O_RDONLY);
    if (ac != 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        print_help();
    if (fstruct.fd == -1)
        return 0;
    start(&fstruct);
    return 0;
}

int start(fct_struct_t *fstruct)
{
    load_map(fstruct);
    if (content_map_checker(fstruct) == 84) {
        return 84;
    }
    storage_loc_counter(fstruct);
    player_pos_scan(fstruct);
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    scr_display(fstruct);
    return 0;
}

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("      map file representing the warehouse map, containing '#' ");
    my_putstr("for walls,\n");
    my_putstr("          'P' for the player, 'X' for boxes and 'O' for ");
    my_putstr("storage locations.\n");
}

void scr_display(fct_struct_t *fstruct)
{
    while (true) {
        struct_crates_init(fstruct);
        clear();
        for (int i = 0; i < fstruct->height; i++)
            mvprintw(i, 0, fstruct->map[i]);
        fstruct->key_entry = getch();
        player_move(fstruct);
        stucked_crates(fstruct);
        storage_locations(fstruct);
        if (fstruct->key_entry == ' ') {
            endwin();
            break;
        }
        if (fstruct->blocked_crates == fstruct->nb_crates) {
            endwin();
            break;
        }
        refresh();
    }
}

void storage_locations(fct_struct_t *fstruct)
{
    if (fstruct->map[fstruct->y[0]][fstruct->x[0]] == ' ')
        fstruct->map[fstruct->y[0]][fstruct->x[0]] = 'O';
}

void storage_loc_counter(fct_struct_t *fstruct)
{
    int *x = malloc(sizeof(int) + 1 * fstruct->nb_of_storage_location);
    int *y = malloc(sizeof(int) + 1 * fstruct->nb_of_storage_location);
    fstruct->nb_of_storage_location = 0;
    for (int i = 0; i < fstruct->height; i++) {
        for (int j = 0; j < my_strlen(fstruct->map[i]); j++) {
            if (fstruct->map[i][j] == 'O') {
                fstruct->nb_of_storage_location++;
            }
        }
    }

    for (int i = 0; i < fstruct->height; i++) {
        for (int j = 0; j < my_strlen(fstruct->map[i]); j++) {
            if (fstruct->map[i][j] == 'O') {
                x[0] = j;
                y[0] = i;
            }
        }
    }
    fstruct->x = x;
    fstruct->y = y;
}