/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** print_tab
*/

#include "../include/settingup.h"
#include "../lib/my/my.h"

void print_board(map_t *map)
{
    for (int i = 0; i < map->rows; ++i) {
        for (int j = 0; j < map->cols; ++j) {
            my_putchar(map->board[i][j]);
        }
        my_putchar('\n');
    }
}
