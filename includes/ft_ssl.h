#ifndef FT_SSL_H
#define FT_SSL_H

#include <stdbool.h>
#include <stdio.h>

#define TRUE 0
#define FALSE 1

#define COMMAND_ERR 1
#define FLAG_ERR 2
#define USAGE 3

# define FLAG_P		1
# define FLAG_Q		2
# define FLAG_R		4
# define FLAG_S		8
# define NO_FLAG	16



bool parsing(char **argv);
void handle_errors(int error_id, char *error);


/*          LIBFT       */
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
#endif