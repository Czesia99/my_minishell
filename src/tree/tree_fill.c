/*
** EPITECH PROJECT, 2019
** Project main function
** File description:
** main
*/

#include "../../include/include.h"

tree_t *fill_tree(tree_t *tree, sep_tab_t *sep, char *test_str)
{
    int j = 0;

    for (int i = 0; j < (TOTAL_SEP); i += 1) {
        if (test_str[i] == '\0') {
            i = 0;
            j += 1;
            if (j == 8)
                return (tree);
        }
        if (sep[j].sep[0] == test_str[i]) {
            printf("'%c' Found.\n", sep[j].sep[0]);
            tree_add_node(&tree, strtok(test_str, sep[j].sep), \
            strtok((i + test_str), sep[j].sep), sep[j].sep);
        }
    }
}

void tree_add_node(tree_t **tree, char *cmdl, char *cmdr, char *separator)
{
    tree_t *tmpnode = NULL;
    tree_t *tmptree = *tree;

    tree_t *new_node = join_tree(new_tree(cmdl, NULL), \
    new_tree(cmdr, NULL), NULL, separator);

    if (tmptree)
    do
    {
        tmpnode = tmptree;
        tmptree = tmptree->left;
        if (!tmptree)
            tmpnode->left = new_node;
    } while (tmptree);
    else
        *tree = new_node;
}