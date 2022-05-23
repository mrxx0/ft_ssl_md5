#include "../includes/ft_ssl.h"
#include <sys/types.h>

/*
    Debug print for md5
*/

void print_md5(t_md5 *md5)
{
    printf("md5->A = %u\n", md5->A);
    printf("md5->B = %u\n", md5->B);
    printf("md5->C = %u\n", md5->C);
    printf("md5->D = %u\n", md5->D);
    printf("md5->dft_size = %zu\n", md5->dft_size);
    printf("md5->pad_size = %zu\n\n", md5->pad_size);
}

/*
    Init md5 structure.
*/

t_md5   *init_new_md5(size_t input_size)
{
    t_md5 *md5;

    md5 = NULL;
    if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
        handle_errors(MALLOC_FAILED, NULL, -1);
    md5->dft_size = input_size;
    if (md5->dft_size % 64 == 56)
        md5->pad_size = 72 + md5->dft_size;
    else
    {
        if (md5->dft_size % 64 < 56)
            md5->pad_size = 64 - md5->dft_size % 64 + md5->dft_size;
        else
            md5->pad_size = 128 - md5->dft_size % 64 + md5->dft_size;
    }
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
        handle_errors(MALLOC_FAILED, NULL, -1);
    ssl->input_size = 0;
    ssl->cmd = 0;
    ssl->offset = 0;
    ssl->flag = 0;
    return (ssl);
}
