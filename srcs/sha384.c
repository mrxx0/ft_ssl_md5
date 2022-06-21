#include "../includes/ft_ssl.h"

/*
    Create sha384 object with associated values.
*/

void sha384 (t_ssl *ssl)
{
    t_sha384 *sha384;

    sha384 = init_new_sha384(ssl->input_size);
    sha384_processing(sha384, ssl);
    clear_sha384(sha384);
}