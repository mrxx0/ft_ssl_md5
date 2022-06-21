#ifndef FT_SSL_H
#define FT_SSL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

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

# define MD5    0
# define SHA256 1
# define SHA384 2

/*      STRUCTURE       */

typedef struct				s_ssl
{
	char					*input;
	char					*output;
	size_t					input_size;
	int						cmd;
	int 					offset;
	int						flag;
	char					pad[3];
	bool					valid;
}							t_ssl;

typedef struct				s_md5
{
	uint32_t				A;
	uint32_t				B;
	uint32_t				C;
	uint32_t				D;
	size_t					dft_size;
	size_t					pad_size;

}							t_md5;

typedef struct				s_sha256
{
	size_t					dft_size;
	size_t					pad_size;

}							t_sha256;

typedef struct				s_sha384
{
	size_t					dft_size;
	size_t					pad_size;

}							t_sha384;

/*      PROTOTYPE       */

bool 			parsing(char **argv, t_ssl *ssl);
int 			handle_errors(int error_id, char *error, int cmd, t_ssl *ssl);
t_ssl 			*init_new_ssl(void);
void    		clear_ssl(t_ssl *ssl, bool flag);
void 			read_input(char **argv, int *argc, t_ssl *ssl);
void 			execute(t_ssl *ssl);
void 			md5 (t_ssl *ssl);
t_md5   		*init_new_md5(size_t input_size);
void   			clear_md5(t_md5 *md5);
void 			md5_processing(t_md5 *md5, t_ssl *ssl);
unsigned char	*prepare_md5_padded_message(char *msg, size_t dft_size, size_t pad_size);
void 			print_hash(char *hash, char *arg, int flag, bool is_stdin);
void 			print_file(char *hash, char *arg, int flag, int cmd);
void 			print_string(char *hash, char *arg, int flag, int cmd);
void 			print_stdin(char *hash, char *arg, int flag);
void 			sha256 (t_ssl *ssl);
t_sha256   		*init_new_sha256(size_t input_size);
void 			sha256_processing(t_sha256 *sha256, t_ssl *ssl);
void   			clear_sha256(t_sha256 *sha256);
void			sha384(t_ssl *ssl);
t_sha384   		*init_new_sha384(size_t input_size);
void 			sha384_processing(t_sha384 *sha384, t_ssl *ssl);
void   			clear_sha384(t_sha384 *sha384);

/*		SHA256 BINARY OPERATIONS	*/

uint32_t	rightrotate(uint32_t x, uint32_t y);
uint32_t    rightshift(uint32_t x, uint32_t y);
uint32_t    ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t    maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t    ssig0(uint32_t x);
uint32_t    ssig1(uint32_t x);
uint32_t    bsig0(uint32_t x);
uint32_t    bsig1(uint32_t x);
uint32_t    S0(uint32_t x);
uint32_t    S1(uint32_t x);
uint32_t    s0(uint32_t x);
uint32_t    s1(uint32_t x);

/*          LIBFT       */

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*strnjoins(char *s1, char *s2, size_t len1, size_t len2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t n);
int     ft_strlen_nonl(char *str);

#endif
