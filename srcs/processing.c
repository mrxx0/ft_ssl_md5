#include "../includes/ft_ssl.h"

void md5_processing(t_md5 *md5)
{
    u_int64_t i;
    u_int64_t j;

    i = 0;
    while (i < md5->pad_size)
    {
        j = 0;
        while (j < 64)
        {
            j++;
        }
        i += 64;
    }
}