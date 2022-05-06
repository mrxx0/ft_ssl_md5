#include "../includes/ft_ssl.h"

/*
    Here we are going to apply 4 functions (FGHI) on the buffers.
    The function applied depends on the constant i (from 0 to 64).
*/

void md5_constant_loop(t_md5 *md5, int j)
{
    (void)md5;
    (void)j;
    /*
    4 rounds :
    0 16  | round 1
    17 32 | round 2
    33 48 | round 3
    49 64 | round 4
    */
}

/*
    Here ABCD word are getting updated as soon as a the 4 function from 
    @md5_constant_loop are applied
*/

void md5_update_abcd(t_md5 *md5)
{
    (void) md5;
    // ABCD are updated with result from the Message Digest from last round
}

/*
    This is where the MD5 is created.
    There are md5->pad_size / 64 rounds.
    Each round is composed of :
    - Apply FGHI functions
    - Update ABCD word
*/

void md5_processing(t_md5 *md5)
{
    u_int64_t i;
    u_int64_t j;

    i = 0;
    while (i < md5->pad_size)
    {
        j = 0;
        md5_update_abcd(md5);
        while (j < 64)
        {
            md5_constant_loop(md5, j);
            // Loop on FGHI function with 64 constants
            j++;
        }
        i += 64;
        printf("%ld round done\n", i / 64);
    }
}