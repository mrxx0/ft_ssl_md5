#include "../includes/ft_ssl.h"

/*
    All binary operation needed for @sha256_processing.c
*/

uint32_t    s1(uint32_t x)
{
    return (rightrotate(x, 19) ^ rightrotate(x, 61) ^ rightrotate(x, 6));
}

uint32_t    s0(uint32_t x)
{
    return (rightrotate(x, 1) ^ rightrotate(x, 8) ^ rightrotate(x, 7));
}

uint32_t    S1(uint32_t x)
{
    return (rightrotate(x, 14) ^ rightrotate(x, 18) ^ rightrotate(x, 41));
}

uint32_t    S0(uint32_t x)
{
    return (rightrotate(x, 28) ^ rightrotate(x, 34) ^ rightrotate(x, 39));
}

uint32_t    bsig1(uint32_t x)
{
    return (rightrotate(x, 6) ^ rightrotate(x, 11) ^ rightrotate(x, 25));
}

uint32_t    bsig0(uint32_t x)
{
    return (rightrotate(x, 2) ^ rightrotate(x, 13) ^ rightrotate(x, 22));
}

uint32_t    ssig1(uint32_t x)
{
    return (rightrotate(x, 17) ^ rightrotate(x, 19) ^ rightshift(x, 10));
}

uint32_t    ssig0(uint32_t x)
{
    return (rightrotate(x, 7) ^ rightrotate(x, 18) ^ rightshift(x, 3));
}

uint32_t    maj(uint32_t x, uint32_t y, uint32_t z)
{
    return ((x & y) ^ (x & z) ^ (y & z));
}

uint32_t    ch(uint32_t x, uint32_t y, uint32_t z)
{
    return ((x & y) ^ ((~x) & z));
}

uint32_t    rightshift(uint32_t x, uint32_t y)
{
    return ((x) >> (y));
}

uint32_t	rightrotate(uint32_t x, uint32_t y)
{
	return ((x >> y) | (x << (32 - y)));
}