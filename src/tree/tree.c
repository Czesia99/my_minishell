/*
** EPITECH PROJECT, 2019
** Sets of function for tree manipulation
** File description:
** tree
*/

#include "../../include/include.h"

tree_t *new_tree(char *cmd, char *separator)
{
    tree_t *new_tree = malloc(sizeof(tree_t));
    elem_t *elem = new_elem(cmd, separator);

    if (!new_tree) {
        perror("Tree malloc FAILED.\n");
        return (NULL);
    }
    new_tree->elem = elem;
    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->parent = NULL;
    return (new_tree);
}

tree_t *join_tree(tree_t *left, tree_t *right, char *cmd, char *separator)
{
    tree_t *new_parent_tree = new_tree(cmd, separator);

    new_parent_tree->left = left;
    new_parent_tree->right = right;
    if (left)
        left->parent = new_parent_tree;
    if (right)
        right->parent = new_parent_tree;
    return (new_parent_tree);
}

void free_tree(tree_t *tree)
{
    if (tree) {
        if (tree->elem)
            free_elem(tree->elem);
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}