#include "../includes/ft_ssl.h"

/*
    Create sha512 object with associated values.
*/

void sha512 (t_ssl *ssl)
{
    t_sha512 *sha512;

    sha512 = init_new_sha512(ssl->input_size);
    sha512_processing(sha512, ssl);
    clear_sha512(sha512);
}