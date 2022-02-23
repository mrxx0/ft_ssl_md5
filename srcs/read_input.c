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
        printf("%s\n", "FAIL OPEN"); //errno
    // if bad fd, check arg if it's a flag -> error handling
    if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
        printf("%s\n", "FAIL OPEN"); //err isdir
    return (fd);
}

u_int64_t get_input_size(int fd)
{
    struct stat	buf;

	if (fstat(fd, &buf) != 0)
		return (0);
	return (buf.st_size / 10);
}

/*
    Reads input from string/file
*/

void         read_input_file(t_ssl *ssl, char *input)
{
    int fd;
    char *buffer;
    ssize_t read_return = 0;
    u_int64_t buffer_size;

    fd = open_input(ssl, input);
    buffer_size = get_input_size(fd);
    if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buffer_size + 1))))
    {
        close(fd);
        handle_errors(MALLOC_FAILED, NULL); // exit
    }
    while ((read_return = read(fd, buffer, buffer_size)) > 0)
    {
        if (!(ssl->input = strnjoins(
		ssl->input, buffer, ssl->input_size, read_return)))
		{
            printf("%s\n", "FAIL");
            return;
        }
        ssl->input_size += read_return;
		ft_bzero(buffer, buffer_size);
    }
    if (fd > 2)
        close(fd);
    if (buffer)
        free(buffer);
    // if error malloc empty string
    // printf("reading from file on fd = %d: %s\n", fd, input);
    // printf("Size of %s = %lu\n", input, buffer_size);
    // printf("content = \n%s\n", ssl->input);
    return ;
}

/*
    Dispatch reading method from stdin or string/file
*/

bool read_input(char **argv, int *argc, t_ssl *ssl)
{
    int i = ssl->offset;
    printf("offset = %d | argc = %d\n", ssl->offset, *argc);
    // loop to iterate on sting and -s flag
    if ((ssl->flag & FLAG_P) != 0)
            read_input_stdin(ssl);
    else if (ssl->offset == *argc)
            read_input_stdin(ssl);
    // Dispatch to hash algorithm
    // Clear SSL input/input_size//output
    clear_ssl(ssl);
    while (i < *argc)
    {
        read_input_file(ssl, argv[i]);
        // Dispatch to hash algorithm
        // Clear SSL input/input_size//output
        clear_ssl(ssl);
        i++;
    }
    return (TRUE);
}