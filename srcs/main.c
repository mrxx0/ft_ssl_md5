#include "../includes/ft_ssl.h"

void print_info_ssl(t_ssl *ssl)
{
	/*char					*input;
	char					*output;
	size_t					input_size;
    int                     cmd;
	int						error;
	int                     flag;*/

	printf("%s\n", "-------------------------------");
	printf("input = %s\n", ssl->input);
	printf("output = %s\n", ssl->output);
	printf("input_size = %zu\n", ssl->input_size);
	if (ssl->cmd == MD5)
		printf("cmd = %s\n", "MD5");
	else if (ssl->cmd == SHA256)
		printf("cmd = %s\n", "SHA256");
	else
		printf("cmd = %d\n", ssl->cmd);
	printf("error = %d\n", ssl->error);
	printf("flag = %d\n", ssl->flag);

}

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
		executing_from(argv, ssl);
		print_info_ssl(ssl);
		free(ssl);
		return (TRUE);
	}
	handle_errors(USAGE, NULL);
	return (1);
}
