#include "../includes/ft_ssl.h"

/*
    Debug print for md5
*/

void print_md5(t_md5 *md5)
{
    printf("md5->A = %u\n", md5->A);
    printf("md5->B = %u\n", md5->B);
    printf("md5->C = %u\n", md5->C);
    printf("md5->D = %u\n", md5->D);
    printf("md5->dft_size = %zu\n", md5->dft_size);
    printf("md5->pad_size = %zu\n\n", md5->pad_size);
}

/*
    Pad msg string len from dft_size to pad_size (multiple of (512-64) bits).
    Append '1' bit to the end of the message and fill as many 0 required.
*/

char	*prepare_md5_padded_message(char *msg, size_t dft_size, size_t pad_size)
{
    printf("dft_size = %zu\npad_size = %zu\n", dft_size, pad_size);
	char				*new;
    size_t              cursor = dft_size + 1;

	if (!(new = (char *)ft_memalloc((pad_size))))
		return (NULL);
	new = ft_memcpy((void *)new, (void *)msg, dft_size);
	new[dft_size] = (unsigned char)0b10000000;
    while(cursor < pad_size)
    {
        new[cursor++] = 0;
    }
	return (new);
}

/*
    Init md5 structure.
*/

t_md5   *init_new_md5(char *input, size_t input_size)
{
    t_md5 *md5;

    md5 = NULL;
    if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
        handle_errors(MALLOC_FAILED, NULL);
    md5->A = 0x67452301;
    md5->B = 0xEFCDAB89;
    md5->C = 0x98BADCFE;
    md5->D = 0x10325476;
    md5->dft_size = input_size;
    if (md5->dft_size % 64 == 56)
        md5->pad_size = 72 + md5->dft_size;
    else
    {
        if (md5->dft_size % 64 < 56)
            md5->pad_size = 64 - md5->dft_size % 64 + md5->dft_size;
        else
            md5->pad_size = 128 - md5->dft_size % 64 + md5->dft_size;
    }
    char *tmp = prepare_md5_padded_message(input, md5->dft_size, md5->pad_size);
    printf("input = [%p]\npaded = [%p]\n", input, tmp);

    print_md5(md5);
    free(tmp);
    return (md5);
}

/*
    Init ssl structure.
*/

t_ssl   *init_new_ssl(void)
{
    t_ssl *ssl;

    ssl = NULL;
    if (!(ssl = (t_ssl *)ft_memalloc(sizeof(t_ssl))))
        handle_errors(MALLOC_FAILED, NULL);
    ssl->input_size = 0;
    ssl->cmd = 0;
    ssl->offset = 0;
    ssl->flag = 0;
    return (ssl);
}