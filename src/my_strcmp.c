/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** ..
*/

int my_strncmp(char *str, char *cmp, int n)
{
    for (int i = 0; i < n && str[i]; i++)
        if (str[i] != cmp[i])
            return (str[i] - cmp[i]);
    return (0);
}

int my_strcmp(char *str, char *cmp)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != cmp[i])
            return (str[i] - cmp[i]);
    return (0);
}

int my_strcmp_equal(char *str, char *cmp)
{
    for (int i = 0; str[i] != '='; i++)
        if (str[i] != cmp[i])
            return (str[i] - cmp[i]);
    return (0);
}