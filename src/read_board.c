/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** read_board
*/

#include "../include/settingup.h"
#include "../lib/my/my.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void map_info(int fd, char *buf, int *rows, int *cols)
{
    char c;
    int i = 0;

    while (read(fd, &c, 1) > 0 && c != '\n') {
        if (i < 99) {
            buf[i] = c;
            i++;
        }
    }
    buf[i] = '\0';
    *rows = my_getnbr(buf);
    *cols = 0;
    while (read(fd, &c, 1) > 0 && c != '\n')
        (*cols)++;
}

static void fill_row_content(int fd, char *line, int cols)
{
    int j;

    for (j = 0; j < cols; ++j) {
        if (read(fd, &line[j], 1) <= 0)
            line[j] = '.';
    }
    line[cols] = '\0';
}

static void fill_lines(int fd, char **board, int rows, int cols)
{
    char c;
    int i;

    for (i = 0; i < rows; ++i) {
        board[i] = malloc((cols + 1) * sizeof(char));
        if (!board[i])
            return;
        fill_row_content(fd, board[i], cols);
        read(fd, &c, 1);
    }
}

static char **prepare_board(char *file, int *rows, int *cols)
{
    int fd = open(file, O_RDONLY);
    char buf[100];
    char **board;

    if (fd == -1)
        return NULL;
    map_info(fd, buf, rows, cols);
    close(fd);
    if (*rows <= 0 || *cols <= 0)
        return NULL;
    board = malloc(*rows * sizeof(char *));
    return board;
}

char **read_board(char *file, int *rows, int *cols)
{
    char **board = prepare_board(file, rows, cols);
    int fd;
    char c;

    if (!board)
        return NULL;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return NULL;
    while (read(fd, &c, 1) > 0 && c != '\n')
        ;
    fill_lines(fd, board, *rows, *cols);
    close(fd);
    return board;
}
