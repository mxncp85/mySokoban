/*
** EPITECH PROJECT, 2022
** myls
** File description:
** my header
*/

#ifndef MY_H_
    #define MY_H_
    #include <ncurses.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    typedef struct fct_struct {
        int fd;
        int height;
        int file_len;
        char **map;
        int player_x;
        int player_y;
        int key_entry;
        int face_up_down_touch;
        int face_left_right_touch;
        int blocked_crates;
        int nb_crates;
        int *storage_position_x;
        int *storage_position_y;
        int nb_of_storage_location;
        int *x;
        int *y;
    }fct_struct_t;

    int my_compute_power_rec(int, int);
    int my_compute_square_root(int);
    int my_find_prime_sup(int);
    int my_is_prime_it(int);
    int my_is_prime(int);
    int my_isneg(int);
    int my_put_nbr(int);
    void display(int, char);
    int my_pow(int, int);
    void my_putchar(char);
    int my_putstr(char const *);
    char *my_revstr(char*);
    char rev_char(char, char);
    int my_str_isalpha(char const *);
    int my_str_islower(char const *);
    int my_str_isnum(char const *);
    int my_str_isprintable(char const *);
    int my_str_isupper(char const *);
    char *my_strcapitalize(char *);
    char *my_strcat(char * , char const *);
    char *my_strcpy(char *, char const *);
    int my_strlen(char const *);
    char *my_strlowcase(char *);
    char *my_strncat(char *, char const *, int);
    int my_strncmp(char const   *, char const *, int);
    char *my_strncpy(char *, char const *, int);
    char *my_strstr(char *, char const *);
    char *my_strupcase(char *);
    void my_swap(int *,int *);
    char *my_strdup(char const *);
    int my_show_word_array(char * const *tab);
    int my_put_float(double nbr , int precision);
    int my_putnbr_base_long(long nbr, char *base, int precision);

    void load_map(fct_struct_t *fstruct);
    int content_map_checker(fct_struct_t *fstruct);
    int count_line(char *input_map, fct_struct_t *fstruct);
    char** map_to_array(fct_struct_t *fstruct, char *map_file, char **map);
    int map_char_detector(fct_struct_t *fstruct, int i);

    void player_pos_scan(fct_struct_t *fstruct);
    void scr_display(fct_struct_t *fstruct);
    void print_help(void);
    int start(fct_struct_t *fstruct);

    void player_position_save(fct_struct_t *fstruct, int i, int j);
    void player_move(fct_struct_t *fstruct);
    void player_move_forward(fct_struct_t *fstruct);
    void player_move_backward(fct_struct_t *fstruct);
    void player_move_left(fct_struct_t *fstruct);
    void player_move_right(fct_struct_t *fstruct);

    void player_crate_move_forward(fct_struct_t *fstruct);
    void player_crate_move_backward(fct_struct_t *fstruct);
    void player_crate_move_left(fct_struct_t *fstruct);
    void player_crate_move_right(fct_struct_t *fstruct);

    void key_forward(fct_struct_t *fstruct);
    void key_backard(fct_struct_t *fstruct);
    void key_left(fct_struct_t *fstruct);
    void key_right(fct_struct_t *fstruct);
    void key_move_crate_forward(fct_struct_t *fstruct);
    void key_move_crate_backward(fct_struct_t *fstruct);
    void key_move_crate_left(fct_struct_t *fstruct);
    void key_move_crate_right(fct_struct_t *fstruct);

    void stucked_crates(fct_struct_t *fstruct);
    void struct_crates_init(fct_struct_t *fstruct);

    void faces_contact_detect(fct_struct_t *fstruct, int i, int j);
    void storage_locations(fct_struct_t *fstruct);
    void storage_loc_counter(fct_struct_t *fstruct);
#endif /* !MY_H_ */
