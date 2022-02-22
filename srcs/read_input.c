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
    Returns the fd index to open the input.
*/

int open_input(t_ssl *ssl, char *input)
{
    int fd;
    struct stat buf;

    (void)ssl;

    if ((fd = open(input, O_RDONLY)) == -1)
        printf("%s\n", "FAIL OPEN");
    if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
        printf("%s\n", "FAIL OPEN");
    return (fd);
}

/*
    Reads input from string/file
*/

void         read_input_file_string(t_ssl *ssl, char *input)
{
    int fd;
    // char *buffer;
    // ssize_t read_return;
    // u_int64_t buffer_size;

    fd = open_input(ssl, input);
    printf("reading from file string on fd = %d: %s\n", fd, input);
    return ;
}

/*
    Dispatch reading method from stdin or string/file
*/

bool read_input(char **argv, int *argc, t_ssl *ssl)
{
    int i = 2;
    // loop to iterate on sting and -s flag
    while (i <= *argc)
    {
        if ((ssl->flag & FLAG_P) != 0)
            read_input_stdin(ssl);
        else if (*argc == 0)
            read_input_stdin(ssl);
        else
            read_input_file_string(ssl, argv[i]);
        
        // Dispatch to hash algorithm
        // Clear SSL input/input_size//output
        i++;
    }
    
    (void)argv;
    return (TRUE);
}