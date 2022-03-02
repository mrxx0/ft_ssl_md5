#ifndef FT_SSL_H
#define FT_SSL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/*      BOOLEAN        */

# define TRUE 0
# define FALSE 1

/*      ERROR CODE     */

# define COMMAND_ERR 1
# define FLAG_ERR 2
# define USAGE 3
# define MALLOC_FAILED 4
# define REPETED_FLAG 5
# define INVALID_FILE_DIRECTORY 6
# define MISSING_ARG 7

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
	int 					offset;
	int                     flag;
    char                    pad[4];
}							t_ssl;

typedef struct				s_md5
{
	char					*input;
	char					*output;
	size_t					input_size;
    int                     cmd;
	int 					offset;
	int                     flag;
    char                    pad[4];
}							t_md5;

bool 	parsing(char **argv, t_ssl *ssl);
void 	handle_errors(int error_id, char *error);
t_ssl 	*init_new_ssl(void);
void    clear_ssl(t_ssl *ssl);
bool 	read_input(char **argv, int *argc, t_ssl *ssl);
void 	execute(t_ssl *ssl);
void 	md5 (t_ssl *ssl);

/*          LIBFT       */

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*strnjoins(char *s1, char *s2, size_t len1, size_t len2);
#endif