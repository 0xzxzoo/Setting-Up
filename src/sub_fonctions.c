/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** fonctions
*/

#include <stdlib.h>

void free_int_tab(int **tab, int size)
{
    int j;

    for (j = 0; j < size; ++j)
        free(tab[j]);
    free(tab);
}

int **int_tab(int rows, int cols)
{
    int **tab = malloc(rows * sizeof(int *));
    int i;
    int k;

    if (!tab)
        return NULL;
    for (i = 0; i < rows; ++i) {
        tab[i] = malloc(cols * sizeof(int));
        if (!tab[i]) {
            free_int_tab(tab, i);
            return NULL;
        }
        for (k = 0; k < cols; ++k)
            tab[i][k] = 0;
    }
    return tab;
}
