#ifndef FT_SSL_H
#define FT_SSL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*      BOOLEAN        */

# define TRUE 0
# define FALSE 1

/*      ERROR CODE     */

# define COMMAND_ERR 1
# define FLAG_ERR 2
# define USAGE 3
# define MALLOC_FAILED 4
# define REPETED_FLAG 5

/*      FLAGS CODE     */

# define FLAG_P		1
# define FLAG_Q		2
# define FLAG_R		4
# define FLAG_S		8
# define NO_FLAG	16

/*      CMD CODE       */

# define MD5    1
# define SHA256 2

typedef struct				s_ssl
{
	char					*input;
	char					*output;
	size_t					input_size;
    int                     cmd;
	int						error;
	int                     flag;
    char                    pad[4];
}							t_ssl;

bool parsing(char **argv, t_ssl	*ssl);
void handle_errors(int error_id, char *error);
t_ssl   *init_new_ssl(void);
void execution_from(char **argv, t_ssl *ssl);

/*          LIBFT       */
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memalloc(size_t size);
#endif