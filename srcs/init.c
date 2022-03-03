#include "../includes/ft_ssl.h"

/*
    Init md5 structure.
*/

t_md5   *init_new_md5(size_t input_size)
{
    t_md5 *md5;

    md5 = NULL;
    if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
        handle_errors(MALLOC_FAILED, NULL);
    md5->A = 0x67452301;
    md5->B = 0xEFCDAB89;
    md5->C = 0x98BADCFE;
    md5->D = 0x10325476;
    md5->dft_size = input_size;
    
    return (md5);
}

/*
    Init ssl structure.
*/

t_ssl   *init_new_ssl(void)
{
    t_ssl *ssl;

    ssl = NULL;
    if (!(ssl = (t_ssl *)ft_memalloc(sizeof(t_ssl))))
        handle_errors(MALLOC_FAILED, NULL);
    ssl->input_size = 0;
    ssl->cmd = 0;
    ssl->offset = 0;
    ssl->flag = 0;
    return (ssl);
}