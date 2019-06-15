/*
** EPITECH PROJECT, 2019
** Sets of function for tree manipulation
** File description:
** tree
*/

#include "../../include/include.h"

void print_parent_elem(tree_t *tree)
{
    if (tree->parent->elem->cmd) {
        if (tree->elem->cmd)
            printf("(%s) -> %s\n", tree->parent->elem->cmd, \
            tree->elem->cmd);
        if (tree->elem->separator)
            printf("(%s) -> %s\n", tree->parent->elem->cmd, \
            tree->elem->separator);
    }
    if (tree->parent->elem->separator) {
        if (tree->elem->cmd)
            printf("(%s) -> %s\n", tree->parent->elem->separator, \
            tree->elem->cmd);
        if (tree->elem->separator)
            printf("(%s) -> %s\n", tree->parent->elem->separator, \
            tree->elem->separator);
    }
}

void print_root(tree_t *tree)
{
    printf("ROOT:\n");
    if (tree->elem->cmd)
        printf("(%s)\n\n", tree->elem->cmd);
    if (tree->elem->separator)
        printf("(%s)\n\n", tree->elem->separator);
}

void print_tree_side(tree_t *tree, int tree_side)
{
    static int i = 0;
    static int j = 0;

    if (tree_side == LEFT) {
        if (!i) {
            write(1, "Printing Left Side.\n", 20);
            i = 1;
        }
    }
    if (tree_side == RIGHT) {
        if (!j) {
            write(1, "Printing Right Side.\n", 21);
            j = 1;
        }
    }
}

int tree_exec(tree_t *tree)
{
    if (!tree) {
        printf("Error: Cannot exec empty tree.\n");
        return (0);
    }
    if (tree->parent != NULL)
            print_parent_elem(tree);
    if (tree->left) {
        print_tree_side(tree, LEFT);
        tree_exec(tree->left);
    }
    if (tree->right) {
        print_tree_side(tree, RIGHT);
        tree_exec(tree->right);
    }
    return (1);
}
