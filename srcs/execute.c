#include "../includes/ft_ssl.h"

/*
    Dispatch ssl to desired hash from user.
*/

void execute(char *input, size_t input_size, bool cmd)
{
    printf("\nExecuting...\n");
    if (cmd == MD5)
        md5(input, input_size);
    // else if (ssl->cmd == SHA256)
    //     sha256(ssl);
}