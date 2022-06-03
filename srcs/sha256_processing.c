#include "../includes/ft_ssl.h"
#include <stdint.h>
#include <sys/types.h>

/*		CONSTANT SHA256		*/

static uint32_t h0 = 0x6a09e667;
static uint32_t h1 = 0xbb67ae85;
static uint32_t h2 = 0x3c6ef372;
static uint32_t h3 = 0xa54ff53a;
static uint32_t h4 = 0x510e527f;
static uint32_t h5 = 0x9b05688c;
static uint32_t h6 = 0x1f83d9ab;
static uint32_t h7 = 0x5be0cd19;

static uint32_t K[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

#define RIGHTROTATE(X, Y) (((X) >> (Y)) | ((X << (32 - (Y)))))
#define RIGHTSHIFT(X, Y) ((X) >> (Y))
#define CH(X, Y, Z) ((X & Y) ^ ((-X) & Z))
#define MAJ(X, Y, Z) ((X & Y) ^ (X & Z) ^ (Y & Z))
#define SSIG0(X) (RIGHTROTATE(X, 7) ^ RIGHTROTATE(X, 18) ^ RIGHTSHIFT(X, 3))
#define SSIG1(X) (RIGHTROTATE(X, 17) ^ RIGHTROTATE(X, 19) ^ RIGHTSHIFT(X, 10))
#define BSIG0(X) (RIGHTROTATE(X, 2) ^ RIGHTROTATE(X, 13) ^ RIGHTROTATE(X, 22))
#define BSIG1(X) (RIGHTROTATE(X, 6) ^ RIGHTROTATE(X, 11) ^ RIGHTROTATE(X, 25))
#define S0(X) (RIGHTROTATE(X, 28) ^ RIGHTROTATE(X, 34) ^ RIGHTROTATE(X, 39))
#define S1(X) (RIGHTROTATE(X, 14) ^ RIGHTROTATE(X, 18) ^ RIGHTROTATE(X, 41))
#define s0(X) (RIGHTROTATE(X, 1) ^ RIGHTROTATE(X, 8) ^ RIGHTROTATE(X, 7))
#define s1(X) (RIGHTROTATE(X, 19) ^ RIGHTROTATE(X, 61) ^ RIGHTROTATE(X, 6))

void sha256_constant_loop(t_sha256 *sha256, unsigned char *input_padded)
{
    (void)sha256;
	uint32_t i = 0;
	uint32_t j = 0;
    uint32_t w[64];
	uint32_t s0_r = 0;
	uint32_t s1_r = 0;
	uint32_t S0_r = 0;
	uint32_t S1_r = 0;
	uint32_t tmp = 0;
	uint32_t tmp2 = 0;
	uint32_t a = h0;
	uint32_t b = h1;
	uint32_t c = h2;
	uint32_t d = h3;
	uint32_t e = h4;
	uint32_t f = h5;
	uint32_t g = h6;
	uint32_t h = h7;

    while (i < 16)
    {
        w[i] = (uint32_t) input_padded[0 + j] << 24 | (uint32_t) input_padded[1 + j] << 16 | (uint32_t) input_padded[2 + j] << 8 | (uint32_t) input_padded[3 + j];
        i++;
        j += 4;
	}

	while (i < 64)
	{
		s0_r = s0(SSIG0(w[i - 15]));
		s1_r = s1(SSIG1(w[i - 2]));
		w[i] = w[i - 16] + s0_r + w[i - 7] + s1_r;
		i++;
	}
	i = 0;
	while (i < 64)
	{
		S1_r = S1(BSIG1(e));
		tmp = h + S1_r + CH(e, f, g) + K[i] + w[i];
		S0_r = S0(BSIG0(a));
		tmp2 = S0_r + MAJ(a, b, c);
		h = g;
		g = f;
		f = e;
		e = d + tmp;
		d = c;
		c = b;
		b = a;
		a = tmp + tmp2;
		i++;
	}
	h0 += a;
	h1 += b;
	h2 += c;
	h3 += d;
	h4 += e;
	h5 += f;
	h6 += g;
	h7 += h;
}

/*
   This is where the SHA256 is created.
   */

void sha256_processing(t_sha256 *sha256, t_ssl *ssl)
{
    uint64_t i= 0;
	size_t              pad_zero = 0;
	unsigned char		*new;
	unsigned char 		*buf;

	if (!(new = (unsigned char *)malloc(sizeof(char) * sha256->pad_size)))
		handle_errors(MALLOC_FAILED, NULL, -1, ssl);
	new = ft_memcpy((void *)new, (void *)ssl->input, sha256->dft_size);
	if (sha256->dft_size % 64 > 55)
		pad_zero = 64 - ((sha256->dft_size % 64) + 1) + 56;
	else
		pad_zero = 64 - ((sha256->dft_size % 64) + 1) - 8;
	new[sha256->dft_size] = (unsigned char)0b10000000;
	ft_memset(new + sha256->dft_size + 1, 0, pad_zero);
    	uint64_t	bit_length = sha256->dft_size * 8;
	for (uint64_t i = 0; i < 8; i++) 
		new[sha256->pad_size - (i + 1)] = bit_length >> 8 * i;
	buf = new;
    while (i < sha256->pad_size)
    {		
        sha256_constant_loop(sha256, buf);
        buf += 64;
        i += 64;
    }
    free(new);
	char *hash = malloc(sizeof(char) * 66);
	if (!hash)
		handle_errors(MALLOC_FAILED, NULL, -1, ssl);
	for (int i = 0; i < 4; i++)
	// 	sprintf(hash + i * 2, "%02x", ((uint8_t *)&a0)[i]);
	// for (int i = 0; i < 4; i++)
	// 	sprintf(hash + 8 + i * 2, "%02x", ((uint8_t *)&b0)[i]);
	// for (int i = 0; i < 4; i++)
	// 	sprintf(hash + 16 + i * 2, "%02x", ((uint8_t *)&c0)[i]);
	// for (int i = 0; i < 4; i++)
	// 	sprintf(hash + 24 + i * 2, "%02x", ((uint8_t *)&d0)[i]);
	hash[65] = '\0';
	ft_bzero(ssl->output, ft_strlen(ssl->output));
	ssl->output = ft_strdup(hash);
	free(hash);
}
