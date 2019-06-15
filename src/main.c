/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include "include.h"

fd_t *init_fd_info(void)
{
    fd_t *info = malloc(sizeof(fd_t));
    vector_t *std_in_out = malloc(sizeof(vector_t));
    vector_t *actual_in_out = malloc(sizeof(vector_t));

    std_in_out->x = dup(0);
    std_in_out->y = dup(1);
    actual_in_out->x = dup(0);
    actual_in_out->y = dup(1);
    info->std_in_out = std_in_out;
    info->actual_in_out = actual_in_out;
    return (info);
}

int main(int ac, char **av, char **env)
{
    char *buff = NULL;
    int a = 0;
    char **tabalias = malloctab1(tabalias);
    siple_t s = {0, 0};
    linked_t *list = create_list(env);
    fd_t *fd_info = init_fd_info();
    shell_t *data = get_shell_data(buff, env);

    (void) ac;
    signal_handling();
    while (1) {
        if (isatty(0)) printf("$~ %s> ", getcwd(NULL, 1024));
        s.buff = my_getline();
        if (s.buff == NULL) return (0);
        if (s.buff[0] == '\0') continue;
        s.buff = clear_str(s.buff);
        s.buff = inib(s.buff);
        get_input(data, s.buff);
        s.a = check_builtins(data, list);
        s = alias(s, tabalias);
        if (s.a == 10) exec(data, list, fd_info, *fd_info->std_in_out);
        s.a = 0;
    }
}
