#include "../includes/ft_ssl.h"

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (parsing(argv) == FALSE)
			return (FALSE);
		return (TRUE);
	}
	handle_errors(USAGE, NULL);
	return (1);
}
