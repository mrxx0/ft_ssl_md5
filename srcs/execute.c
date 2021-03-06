#include "../includes/ft_ssl.h"

/*
    Dispatch ssl to desired hash from user.
*/

void execute(t_ssl *ssl)
{
    if (ssl->cmd == MD5)
        md5(ssl);
    else if (ssl->cmd == SHA256)
        sha256(ssl);
    else if (ssl->cmd == SHA384)
        sha384(ssl);
    else if (ssl->cmd == SHA512)
        sha512(ssl);
}