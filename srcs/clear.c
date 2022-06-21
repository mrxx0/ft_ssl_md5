#include "../includes/ft_ssl.h"

/*
    Clear sha384 structure.
*/

void    clear_sha384(t_sha384 *sha384)
{
    sha384->dft_size = 0;
    sha384->pad_size = 0;
    if (sha384)
        free(sha384);
}


/*
    Clear sha256 structure.
*/

void    clear_sha256(t_sha256 *sha256)
{
    sha256->dft_size = 0;
    sha256->pad_size = 0;
    if (sha256)
        free(sha256);
}

/*
    Clear md5 structure.
*/

void    clear_md5(t_md5 *md5)
{
    md5->A = 0;
    md5->B = 0;
    md5->C = 0;
    md5->D = 0;
    md5->dft_size = 0;
    md5->pad_size = 0;
    if (md5)
        free(md5);
}

/*
    Clear ssl structure.
*/

void    clear_ssl(t_ssl *ssl, bool flag)
{ 
    if (ssl->input)
        ft_strdel(&ssl->input);
    if (ssl->output)
        ft_strdel(&ssl->output);
    ssl->input_size = 0;
    ssl->offset = 0;
    ssl->valid = 1;
    if (flag == 1)
        ssl->flag = 0;
}