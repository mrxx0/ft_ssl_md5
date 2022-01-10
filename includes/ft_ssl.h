#ifndef FT_SSL_H
#define FT_SSL_H

#include <stdbool.h>
#include <stdio.h>

#define TRUE 0
#define FALSE 1

#define COMMAND_ERR 1
#define FLAG_ERR 2
#define USAGE 3



bool parsing(char **argv);
void handle_errors(int error_id, char *error);


/*          LIBFT       */
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
#endif