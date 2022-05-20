#include "../includes/ft_ssl.h"
#include <stdlib.h>
#include <sys/types.h>

/*		CONSTANT MD5		*/

u_int32_t a0 = 0x67452301;
u_int32_t b0 = 0xEFCDAB89;
u_int32_t c0 = 0x98BADCFE;
u_int32_t d0 = 0x10325476;

u_int32_t s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
					5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
					4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
					6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};	

u_int32_t K[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
				0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
				0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
				0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
				0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
				0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
				0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
				0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
				0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
				0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
				0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
				0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
				0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
				0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
				0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
				0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

/*
   Here ABCD word are getting updated as soon as a the 4 function from 
   @md5_constant_loop are applied
   */

void md5_update_abcd(t_md5 *md5)
{
	a0 += md5->A;
	b0 += md5->B;
	c0 += md5->C;
	d0 += md5->D;
	// ABCD are updated with result from the Message Digest from last round
}

/*
   Here we are going to apply 4 functions (FGHI) on the buffers.
   The function applied depends on the constant i (from 0 to 64).
   */

void md5_constant_loop(t_md5 *md5, unsigned char *input_padded)
{
	u_int32_t i = 0;
	u_int32_t *M = (void *)input_padded;
	md5->A = a0;
	md5->B = b0;
	md5->C = c0;
	md5->D = d0;
	while (i < 64)
	{
		u_int32_t F;
		u_int32_t g;
		if (i < 16)
		{
			F = ((md5->B &md5->C) | ((~md5->B) & md5->D));
			g = i;
		}
		else if (i < 32)
		{
			F = (md5->D & md5->B) | ((~md5->D) & md5->C);
			g = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			F = (md5->B ^ md5->C ^ - md5->D);
			g = (3 * i + 5) % 16;
		}
		else 
		{
			F = (md5->C ^(md5->B | (~md5->D)));
			g = (7 * i) % 16; 
		}
		F += md5->A + K[i] + M[g];
		md5->A = md5->D;
		md5->D = md5->C;
		md5->C = md5->B;
		md5->B += (F << s[i] | F >> (32 - s[i]));
		printf("----------\nF = %u\nA = %d\nB = %d\nC = %d\nD = %d\t%d\n",F, md5->A, md5->B, md5->C, md5->D, i);
		i++;

	}
	md5_update_abcd(md5);
	input_padded += 64;
	/*
	   4 rounds :
	   0 16  | round 1
	   17 32 | round 2
	   33 48 | round 3
	   49 64 | round 4
	   */
}

/*
   This is where the MD5 is created.
   There are md5->pad_size / 64 rounds.
   Each round is composed of :
   - Apply FGHI functions
   - Update ABCD word
   */

void md5_processing(t_md5 *md5, char *input)
{
	u_int64_t i;
	unsigned char *input_padded = (unsigned char *)prepare_md5_padded_message(input, md5->dft_size, md5->pad_size);
	i = 0;
	while (i < md5->pad_size)
	{
		md5_constant_loop(md5, input_padded);
		// md5_updddate_abcd(md5);
		i += 64;
	}
	free(input_padded);
	printf("%ld round done\n", i / 64);
	char *hash = malloc(sizeof(char) * 33);
	if (!hash)
		handle_errors(MALLOC_FAILED, NULL);
	for (int i = 0; i < 4; i++)
		sprintf(hash + i * 2, "%02x", ((u_int8_t *)&a0)[i]);
	for (int i = 0; i < 4; i++)
		sprintf(hash + 8 + i * 2, "%02x", ((u_int8_t *)&b0)[i]);
	for (int i = 0; i < 4; i++)
		sprintf(hash + 16 + i * 2, "%02x", ((u_int8_t *)&c0)[i]);
	for (int i = 0; i < 4; i++)
		sprintf(hash + 24 + i * 2, "%02x", ((u_int8_t *)&d0)[i]);
	hash[32] = '\0';
	printf("--------------\n\n\n%s\n", hash);
	free(hash);
}
