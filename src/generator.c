/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** map_build
*/

#include "../include/settingup.h"
#include "../lib/my/my.h"
#include <unistd.h>
#include <stdlib.h>

// clang-format off

static char **init_tab_patern(int size,
    char *pattern, int pattern_len)
{
    int j;
    char **carac_print = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; ++i) {
        carac_print[i] = malloc(sizeof(char) * (size + 1));
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            carac_print[i][j] = pattern[(i * size + j) % pattern_len];
        }
        carac_print[i][size] = '\0';
    }
    carac_print[size] = NULL;
    return carac_print;
}

int run_gen(char *size_str, char *pattern)
{
    int size = my_getnbr(size_str);
    int pattern_len = my_strlen(pattern);
    map_t map;

    if (size <= 0 || pattern_len == 0)
        return 84;
    map.cols = size;
    map.rows = size;
    map.board = init_tab_patern(size, pattern, pattern_len);
    map.tab = int_tab(size, size);
    build_map(&map);
    square_x(&map);
    print_board(&map);
    return 0;
}
