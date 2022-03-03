#include "../includes/ft_ssl.h"

/*
    Clear md5 structure.
*/

void    clear_md5(t_md5 *md5)
{
    if (md5)
        free(md5);
}

/*
    Clear ssl structure.
*/

void    clear_ssl(t_ssl *ssl)
{
    ssl->input_size = 0;
    if (ssl->input)
        free(ssl->input);
    ssl->input = NULL;
    if (ssl->output)
        free(ssl->output);
    ssl->output = NULL;
}