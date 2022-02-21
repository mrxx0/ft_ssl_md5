#include "../includes/ft_ssl.h"

/*
    Reads input from stdin:
    - stock content in ssl->input
    - stock content's size in ssl->input_size
*/

void         read_input_stdin(t_ssl *ssl)
{

	char	buffer[512 + 1];
	char	*stdin;
	ssize_t	read_return;

	stdin = NULL;
	ssl->input_size = 0;
	ft_bzero(buffer, 512 + 1);
	while ((read_return = read(STDIN_FILENO, buffer, 512)) > 0)
	{
		if (!(ssl->input = strnjoins(
		ssl->input, buffer, ssl->input_size, read_return)))
		{
            printf("%s\n", "FAIL");
            return;
        }
		ssl->input_size += read_return;
		ft_bzero(buffer, 512 + 1);
	}
	if (!ssl->input)
		if (!(ssl->input = ft_strdup("")))
		{
            printf("%s\n", "FAIL 2");
            return;
        }
}

/*
    Reads input from string/file
*/

void         read_input_file_string()
{
    printf("reading from file string\n");
    return ;
}
/*
    Dispatch reading method from stdin or string/file
*/

bool read_input(char **argv, int *argc, t_ssl *ssl)
{
    if ((ssl->flag & FLAG_P) != 0)
        read_input_stdin(ssl);
    else if (*argc == 0)
        read_input_stdin(ssl);
    else
        read_input_file_string();
    (void)argv;
    return (TRUE);
}