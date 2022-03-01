#include "../includes/ft_ssl.h"

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
	    t_ssl	*ssl;
		ssl = init_new_ssl();
		if (parsing(argv, ssl) == FALSE)
		{
			free(ssl);
			return (FALSE);
		}
		read_input(argv, &argc, ssl);
		// delete ssl
		if (ssl->input)
			free(ssl->input);
		free(ssl);
		return (TRUE);
	}
	handle_errors(USAGE, NULL);
	return (1);
}
