/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** map_build
*/

#include "../include/settingup.h"

static void max(map_t *map, int i, int j)
{
    if (map->tab[i][j] > map->max_size) {
        map->max_size = map->tab[i][j];
        map->max_row = i;
        map->max_cols = j;
    }
}

static void init_borders(map_t *map)
{
    int j;
    int i;

    for (j = 0; j < map->cols; ++j) {
        if (map->board[0][j] == '.')
            map->tab[0][j] = 1;
        else
            map->tab[0][j] = 0;
        max(map, 0, j);
    }
    for (i = 1; i < map->rows; ++i) {
        if (map->board[i][0] == '.')
            map->tab[i][0] = 1;
        else
            map->tab[i][0] = 0;
        max(map, i, 0);
    }
}

static void process_cell(map_t *map, int i, int j)
{
    int min;
    int a;
    int b;
    int c;

    if (map->board[i][j] == 'o') {
        map->tab[i][j] = 0;
        return;
    }
    a = map->tab[i - 1][j];
    b = map->tab[i][j - 1];
    c = map->tab[i - 1][j - 1];
    min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    map->tab[i][j] = min + 1;
    max(map, i, j);
}

static void compute_rest(map_t *map)
{
    int i;
    int j;

    for (i = 1; i < map->rows; ++i) {
        for (j = 1; j < map->cols; ++j) {
            process_cell(map, i, j);
        }
    }
}

void build_map(map_t *map)
{
    map->max_size = 0;
    map->max_row = 0;
    map->max_cols = 0;
    init_borders(map);
    compute_rest(map);
}
