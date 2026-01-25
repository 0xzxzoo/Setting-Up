/*
** EPITECH PROJECT, 2025
** Project - settingup
** File description:
** algorithm_x
*/

#include "../include/settingup.h"
#include "../lib/my/my.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void square_x(map_t *map)
{
    int size = map->max_size;
    int row = map->max_row;
    int col = map->max_cols;

    for (int i = row - size + 1; i <= row; ++i) {
        for (int j = col - size + 1; j <= col; ++j) {
            map->board[i][j] = 'x';
        }
    }
}
