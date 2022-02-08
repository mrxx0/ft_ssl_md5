#include "../includes/ft_ssl.h"

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
    ssl->error = 0;
    ssl->flag = 0;
    return (ssl);
}