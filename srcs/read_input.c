#include "../includes/ft_ssl.h"

/*
   Reads input from string:
   - stock content in ssl->input
   - stock content's size in ssl->input_size
   */

void        read_input_string(char **argv, int i, t_ssl *ssl)
{
	if (!argv[i])
		handle_errors(MISSING_ARG, NULL);
	ssl->input = ft_strdup(argv[i]);
	ssl->input_size = ft_strlen(ssl->input);
}

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
			handle_errors(MALLOC_FAILED, NULL);
		ssl->input_size += read_return;
		ft_bzero(buffer, 512 + 1);
	}
	close(STDIN_FILENO);
	if (!ssl->input)
		if (!(ssl->input = ft_strdup("")))
			handle_errors(MALLOC_FAILED, NULL);
}

/*
   Returns the fd index to open the input.
   */

int open_input(char *input)
{
	int fd;
	struct stat buf;

	if ((fd = open(input, O_RDONLY)) == -1)
		handle_errors(INVALID_FILE_DIRECTORY, input);
	if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
		handle_errors(INVALID_FILE_DIRECTORY, input);
	return (fd);
}

/*
   Returns the size / 10 of the file opened.
   */

uint64_t get_input_size(int fd)
{
	struct stat	buf;

	if (fstat(fd, &buf) != 0)
		return (0);
	return (buf.st_size / 10);
}

/*
   Reads input from file:
   - stock content in ssl->input
   - stock content's size in ssl->input_size
   */

void         read_input_file(t_ssl *ssl, char *input)
{
	int fd;
	char *buffer;
	ssize_t read_return = 0;
	uint64_t buffer_size;

	fd = open_input(input);
	buffer_size = get_input_size(fd);
	if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buffer_size + 1))))
	{
		close(fd);
		handle_errors(MALLOC_FAILED, NULL);
	}
	while ((read_return = read(fd, buffer, buffer_size)) > 0)
	{
		if (!(ssl->input = strnjoins(
						ssl->input, buffer, ssl->input_size, read_return)))
		{
			close(fd);
			handle_errors(MALLOC_FAILED, NULL);
		}
		ssl->input_size += read_return;
		ft_bzero(buffer, buffer_size);
	}
	if (fd > 2)
		close(fd);
	if (buffer)
		free(buffer);
}

/*
   Dispatch reading method from stdin or string/file
   */

bool read_input(char **argv, int *argc, t_ssl *ssl)
{
	int i = ssl->offset;
	
	if ((ssl->flag & FLAG_P) != 0)
	{
		read_input_stdin(ssl);
		execute(ssl);
		// Dispatch to hash algorithm
		clear_ssl(ssl, 0);
	}
	if ((ssl->flag & FLAG_S) != 0)
	{
		read_input_string(argv, i, ssl);
		execute(ssl);
		// Dispatch to hash algorithm
		clear_ssl(ssl, 0);
		i++;
	}
	else if (ssl->offset == *argc && (ssl->flag & FLAG_P) == 0)
	{
		read_input_stdin(ssl);
		execute(ssl);
		// Dispatch to hash algorithm
		clear_ssl(ssl, 0);
	}
	while (i < *argc)
	{
		read_input_file(ssl, argv[i]);
		execute(ssl);
		// Dispatch to hash algorithm
		clear_ssl(ssl, 1);
		i++;
	}
	return (TRUE);
}
