#include "../includes/ft_ssl.h"

/*
    All binary operation needed for @shaX_processing.c
*/

uint64_t    s1(uint64_t x)
{
    return (rightrotate(x, 19) ^ rightrotate(x, 61) ^ rightrotate(x, 6));
}

uint64_t    s0(uint64_t x)
{
    return (rightrotate(x, 1) ^ rightrotate(x, 8) ^ rightrotate(x, 7));
}

uint64_t    S1(uint64_t x)
{
    return (rightrotate(x, 14) ^ rightrotate(x, 18) ^ rightrotate(x, 41));
}

uint64_t    S0(uint64_t x)
{
    return (rightrotate(x, 28) ^ rightrotate(x, 34) ^ rightrotate(x, 39));
}

uint64_t    bsig1(uint64_t x)
{
    return (rightrotate(x, 6) ^ rightrotate(x, 11) ^ rightrotate(x, 25));
}

uint64_t    bsig0(uint64_t x)
{
    return (rightrotate(x, 2) ^ rightrotate(x, 13) ^ rightrotate(x, 22));
}

uint64_t    ssig1(uint64_t x)
{
    return (rightrotate(x, 17) ^ rightrotate(x, 19) ^ rightshift(x, 10));
}

uint64_t    ssig0(uint64_t x)
{
    return (rightrotate(x, 7) ^ rightrotate(x, 18) ^ rightshift(x, 3));
}

uint64_t    maj(uint64_t x, uint64_t y, uint64_t z)
{
    return ((x & y) ^ (x & z) ^ (y & z));
}

uint64_t    ch(uint64_t x, uint64_t y, uint64_t z)
{
    return ((x & y) ^ ((~x) & z));
}

uint64_t    rightshift(uint64_t x, uint64_t y)
{
    return ((x) >> (y));
}

uint64_t	rightrotate(uint64_t x, uint64_t y)
{
	return ((x >> y) | (x << (32 - y)));
}