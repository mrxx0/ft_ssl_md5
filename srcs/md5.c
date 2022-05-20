#include "../includes/ft_ssl.h"

/*
    Create md5 object with associated values.
*/

void md5 (t_ssl *ssl)
{
    t_md5 *md5;

    md5 = init_new_md5(ssl->input_size);
    md5_processing(md5, ssl);
    clear_md5(md5);
}