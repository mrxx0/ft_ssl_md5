#include "../includes/ft_ssl.h"
#include <sys/types.h>

/*
    Debug print for sha256
*/

void print_sha256(t_sha256 *sha256)
{
    printf("sha256->dft_size = %zu\n", sha256->dft_size);
    printf("sha256->pad_size = %zu\n\n", sha256->pad_size);
}

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
    Init sha256 structure.
*/

t_sha256   *init_new_sha256(size_t input_size)
{
    t_sha256 *sha256;

    sha256 = NULL;
    if (!(sha256 = (t_sha256 *)ft_memalloc(sizeof(t_sha256))))
        handle_errors(MALLOC_FAILED, NULL, -1, NULL);
    sha256->dft_size = input_size;
    if (sha256->dft_size % 64 == 56)
        sha256->pad_size = 72 + sha256->dft_size;
    else
    {
        if (sha256->dft_size % 64 < 56)
            sha256->pad_size = 64 - sha256->dft_size % 64 + sha256->dft_size;
        else
            sha256->pad_size = 128 - sha256->dft_size % 64 + sha256->dft_size;
    }
    print_sha256(sha256);
    return (sha256);
}

/*
    Init md5 structure.
*/

t_md5   *init_new_md5(size_t input_size)
{
    t_md5 *md5;

    md5 = NULL;
    if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
        handle_errors(MALLOC_FAILED, NULL, -1, NULL);
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
        handle_errors(MALLOC_FAILED, NULL, -1, NULL);
    ssl->input_size = 0;
    ssl->cmd = 0;
    ssl->offset = 0;
    ssl->flag = 0;
    ssl->valid = 1;
    return (ssl);
}
