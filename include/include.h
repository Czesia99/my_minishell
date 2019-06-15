/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#ifndef __INCLUDE__
#define __INCLUDE__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

/*DEFINES*/
#define TOTAL_SEP 8
#define LEFT 0
#define RIGHT 1

/*STRUCTURES*/
typedef struct linked {
    char *str;
    struct linked *next;
} linked_t;

typedef enum {
    semi_colon,
    dble_l_chevron,
    dble_and,
    dble_pipe,
    dble_r_chevron,
    l_chevron,
    r_chevron,
    piipe
} separators;

typedef struct sep_tab_s{
    char *sep;
    separators sep_value;
} sep_tab_t;

typedef struct elem_s {
    char *separator;
    char *cmd;
} elem_t;

typedef struct tree_s {
    elem_t *elem;
    struct tree_s *right;
    struct tree_s *left;
    struct tree_s *parent;
} tree_t;
typedef struct env_s {
    char *content;
    char *name;
    char *line;
    int size;
    struct env_s *next;
} env_t;

typedef struct shell_data_s {
    char *buff;
    char **tab;
    char **env;
    tree_t *tree;
    sep_tab_t *sep_tab;
    char **input;
    int input_length;
    env_t *list_env;
} shell_t;

typedef struct builtin_s {
    char *cmd;
    void (*function)(shell_t *, linked_t *);
} builtin_t;

typedef struct clear {
    char *s;
    int i;
    int j;
    int len;
} clear_t;

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct fd_s {
    vector_t *std_in_out;
    vector_t *actual_in_out;
} fd_t;


typedef struct siple_s {
    char *buff;
    int a;
    int i;
}siple_t;



char *my_strcat1(char *str, char *c);

char *change_old(linked_t **);

char *my_strdup_equal(char const *str);

char *my_strdup(char const *);

int my_strcmp(char *str, char *cmp);

int my_strncmp(char *, char *, int);

char *my_strcat(char *, char *, int, char);

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_nbr(int);

char **my_str_to_word_array(char *, char);

char *clear_str(char *str);

int update_pwd(linked_t **node, char *dir, char);

linked_t *call(char **av, char **envp, char *buff, char *cmp);

void do_cd(shell_t *data, linked_t *list);

char **copy_tab(char **envp);

char **list_to_tab(linked_t *list);

void print_linked(linked_t *list);

linked_t *create_node(char *str);

linked_t *create_list(char **tab);

linked_t *find_node(linked_t *list, char *cmp, int i);

char *my_getline(void);

int my_strlen(char const *str);

int what_to_do(char *buff);

linked_t *do_cd_old(linked_t *list);

char *clear_tab(char *str);


char *my_strncpy(char *dest, char *src, int n);
int check_builtins(shell_t *data, linked_t *list);

char *inib(char *str);

char **malloctab1(char **tab);

int parsing_equal(char *buff);

siple_t stock_alias(char *buff, char **taballias, siple_t);

void printalias(char **taballias, siple_t);

siple_t alias(siple_t, char **);

char *parsetab(char **tab, siple_t s);

int my_strcmp_equal(char *str, char *cmp);

// exec.c
int exec(shell_t *, linked_t *, fd_t *, vector_t);

// sig.c
int sig(int status);
int signal_handling(void);

//tree.c
tree_t *new_tree(char *cmd, char *separator);
tree_t *join_tree(tree_t *left, tree_t *right, char *cmd, char *separator);
void free_tree(tree_t *tree);

//tree_elem.c
elem_t *new_elem(char *cmd, char *separator);
void free_elem(elem_t *elem);

//tree_sep.c
sep_tab_t *new_sep_tab(void);

//tree_print.c
int tree_exec(tree_t *tree);

//tree_fill.c
void tree_add_node(tree_t **tree, char *cmdl, char *cmdr, char *separator);
tree_t *fill_tree(tree_t *tree, sep_tab_t *sep, char *test_str);

//tree_cpy.c
char *my_strcpy_tree(char *dest, char const *src);

//env_manage.c
int check_env_args(shell_t *shell);
void change_env_line(shell_t *shell, char *name, char *line);
char *create_env_line(shell_t *shell);
void get_env_content(env_t *elem, char *line);
void convert_env_in_tab(shell_t *shell);

//env_functions.c
void do_exit(shell_t *data, linked_t *list);
void do_env(shell_t *shell, linked_t *list);
void do_setenv(shell_t *shell, linked_t *list);
void do_unsetenv(shell_t *shell, linked_t *list);
void setenv_existing_line(env_t *tmp, char *line);

//initialisation.c
env_t *env_list_add(env_t *list, char *line);
env_t *env_list_init(char **env);
shell_t *get_shell_data(char *buff, char **env);
void get_input(shell_t *data, char *buff);

//built_in.c
int check_builtins(shell_t *data, linked_t *list);


#endif
