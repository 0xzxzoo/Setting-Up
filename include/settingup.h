/*
** EPITECH PROJECT, 2025
** PROJECT - Setting_Up
** File descprition:
** Setting_Up_Header
*/

#ifndef SETTING_UP_H
#define SETTING_UP_H

typedef struct map_s {
        int rows;
        int cols;
        int max_size;
        int max_row;
        int max_cols;
        char **board;
        int **tab;
} map_t;

int **int_tab(int rows, int cols);

void build_map(map_t *map);

void print_board(map_t *map);

char **read_board(char *file, int *rows, int *cols);

void square_x(map_t *map);

int run_gen(char *size_str, char *pattern);

#endif// SETTING_UP_H
