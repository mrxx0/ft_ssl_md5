#include "../includes/ft_ssl.h"

/*
    Create sha256 object with associated values.
*/

void sha256 (t_ssl *ssl)
{
    t_sha256 *sha256;

    sha256 = init_new_sha256(ssl->input_size);
    sha256_processing(sha256, ssl);
    clear_sha256(sha256);
}