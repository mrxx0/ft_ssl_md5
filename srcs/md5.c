#include "../includes/ft_ssl.h"

/*
    Create md5 object with associated values.
*/

void md5 (char *input, size_t input_size)
{
    t_md5 *md5;

    (void)input;
    printf("-> HASING IN MD5 <-\n");
    printf("-> INIT MD5 <-\n");
    md5 = init_new_md5(input_size);
    printf("-> STEP MD5 <-\n");
    md5_processing(md5, input);
    printf("-> CLEAR MD5 <-\n");
    clear_md5(md5);
}