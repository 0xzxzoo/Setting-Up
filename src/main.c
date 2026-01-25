/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** main
*/

#include "../include/settingup.h"
#include "../lib/my/my.h"

int main(int argc, char **argv)
{
    map_t map;

    if (argc == 2) {
        map.board = read_board(argv[1], &map.rows, &map.cols);
        if (!map.board)
            return 84;
        map.tab = int_tab(map.rows, map.cols);
        if (!map.tab)
            return 84;
        build_map(&map);
        square_x(&map);
        print_board(&map);
    }
    if (argc == 3) {
        return run_gen(argv[1], argv[2]);
    }
    return 0;
}
