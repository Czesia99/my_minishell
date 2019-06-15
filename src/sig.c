/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** sig
*/

#include "include.h"

void signal_handler(int sig, siginfo_t *siginfo, void *context)
{
    (void)sig;
    (void)context;
    (void)siginfo;
    exit(84);
}

int signal_handling(void)
{
    struct sigaction *act = malloc(sizeof(struct sigaction));

    act->sa_sigaction = &signal_handler;
    act->sa_flags = SA_SIGINFO;
    if (sigaction(SIGSEGV, act, NULL) < 0)
        return (84);
    return (0);
}

int sig(int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        write(2, "Segmentation fault\n", 20);
        return (status);
    }
    if (WTERMSIG(status) == SIGFPE) {
        write(2, "Floating exception (core dumped)\n", 34);
        return (status);
    }
    return (0);
}
