#include "../includes/ft_ssl.h"

/*
    Create md5 object with associated values.
*/

void md5 (char *input, size_t input_size)
{
    t_md5 *md5;

    (void)input;
    printf("Hasing in md5\n");
    md5 = init_new_md5(input, input_size);
    clear_md5(md5);
}