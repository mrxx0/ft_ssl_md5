#include "../includes/ft_ssl.h"

/*
    Create md5 object with associated values.
*/

void md5 (char *input, size_t input_size)
{
    t_md5 *md5;

    md5 = init_new_md5(input_size);
    md5_processing(md5, input);
    clear_md5(md5);
}