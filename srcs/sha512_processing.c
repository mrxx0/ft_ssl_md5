#include "../includes/ft_ssl.h"

/*		CONSTANT SHA512		*/

static uint64_t h0 = 0x6a09e667f3bcc908;
static uint64_t h1 = 0xbb67ae8584caa73b;
static uint64_t h2 = 0x3c6ef372fe94f82b;
static uint64_t h3 = 0xa54ff53a5f1d36f1;
static uint64_t h4 = 0x510e527fade682d1;
static uint64_t h5 = 0x9b05688c2b3e6c1f;
static uint64_t h6 = 0x1f83d9abfb41bd6b;
static uint64_t h7 = 0x5be0cd19137e2179;

static uint64_t K[80] = {0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 
    0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
    0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
    0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
    0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
    0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b, 
    0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
    0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
    0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
    0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 
    0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
    0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
    0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
    0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
    0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c, 
    0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

/*
   Here we are going to apply functions on the buffers.
   The function applied depends on the constant i (from 0 to 80) and values [a-h].
   */


static void sha512_constant_loop(unsigned char *input_padded)
{
	uint64_t i = 0;
	uint64_t j = 0;
    uint64_t w[80];
	uint64_t t1 = 0;
	uint64_t t2 = 0;
	uint64_t a = h0;
	uint64_t b = h1;
	uint64_t c = h2;
	uint64_t d = h3;
	uint64_t e = h4;
	uint64_t f = h5;
	uint64_t g = h6;
	uint64_t h = h7;

    while (i < 16)
    {
        w[i] = (uint64_t) input_padded[0 + j] << 56 | (uint64_t) input_padded[1 + j] << 48 | (uint64_t) input_padded[2 + j] << 40 | (uint64_t) input_padded[3 + j] << 32 | (uint64_t) input_padded[4 + j] << 24 | (uint64_t) input_padded[5 + j] << 16 | (uint64_t) input_padded[6 + j] << 8 | (uint64_t) input_padded[7 + j];
		i++;
        j += 8;
	}
	while (i < 80)
	{
		w[i] = s1(w[i - 2]) + w[i - 7] + s0(w[i - 15]) + w[i - 16];
		i++;
	}
	i = 0;
	while (i < 80)
	{
		t1 = h + S1(e) + ch(e, f, g) + K[i] + w[i];
		t2 = S0(a) + maj(a, b, c);

		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
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
	Reset value for global variable in case of multiple arguments.
*/

static void reset_H_512()
{
    h0 = 0x6a09e667f3bcc908;
    h1 = 0xbb67ae8584caa73b;
    h2 = 0x3c6ef372fe94f82b;
    h3 = 0xa54ff53a5f1d36f1;
    h4 = 0x510e527fade682d1;
    h5 = 0x9b05688c2b3e6c1f;
    h6 = 0x1f83d9abfb41bd6b;
    h7 = 0x5be0cd19137e2179;
}

/*
   This is where the SHA512 is created.
   */

void sha512_processing(t_sha512 *sha512, t_ssl *ssl)
{
    uint64_t            i = 0;
	size_t              pad_zero = 0;
	unsigned char		*new;
	unsigned char 		*buf;

	if (!(new = (unsigned char *)malloc(sizeof(char) * sha512->pad_size)))
		handle_errors(MALLOC_FAILED, NULL, -1, ssl);
	new = ft_memcpy((void *)new, (void *)ssl->input, sha512->dft_size);
    if (sha512->dft_size % 128 > 111)
		pad_zero = 128 - ((sha512->dft_size % 128) + 1) + 112;
	else
		pad_zero = 128 - ((sha512->dft_size % 128) + 1) - 16;
	new[sha512->dft_size] = (unsigned char)0b10000000;
	ft_memset(new + sha512->dft_size + 1, 0, pad_zero);
    __uint128_t	bit_length = sha512->dft_size * 8;
	for (uint64_t i = 0; i < 16; i++) 
		new[sha512->pad_size - (i + 1)] = bit_length >> 8 * i;
	buf = new;
	reset_H_512();
    while (i < sha512->pad_size)
    {		
        sha512_constant_loop(buf);
        buf += 128;
        i += 128;
    }
	free(new);
    char *hash = malloc(sizeof(char) * 129);
	if (!hash)
		handle_errors(MALLOC_FAILED, NULL, -1, ssl);
	sprintf(hash + 16 * 0, "%016lx", h0);
	sprintf(hash + 16 * 1, "%016lx", h1);
	sprintf(hash + 16 * 2, "%016lx", h2);
	sprintf(hash + 16 * 3, "%016lx", h3);
	sprintf(hash + 16 * 4, "%016lx", h4);
	sprintf(hash + 16 * 5, "%016lx", h5);
	sprintf(hash + 16 * 6, "%016lx", h6);
	sprintf(hash + 16 * 7, "%016lx", h7);
	hash[128] = '\0';
	ft_bzero(ssl->output, ft_strlen(ssl->output));
	ssl->output = ft_strdup(hash);
	free(hash);
}
