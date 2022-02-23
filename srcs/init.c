#include "../includes/ft_ssl.h"


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

/*
    Zeroing ssl structure.
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