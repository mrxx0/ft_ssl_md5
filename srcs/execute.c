#include "../includes/ft_ssl.h"

void execute(t_ssl *ssl)
{
    printf("\nExecuting...\n");
    if (ssl->cmd == MD5)
        md5(ssl);
    // else if (ssl->cmd == SHA256)
    //     sha256(ssl);
}