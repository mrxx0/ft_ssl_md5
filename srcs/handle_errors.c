#include "../includes/ft_ssl.h"


void handle_errors(int error_id, char *error)
{
    if (error_id == COMMAND_ERR)
    {
        printf("ft_ssl: Error: '%s' is an invalid command."
        "\nCommands:"
        "\n\tmd5"
        "\n\tsha256"
        "\nFlags:"
        "\n\t-p -q -r -s\n", error);
    }
    if (error_id == FLAG_ERR)
    {
        printf("ft_ssl: Error: '%s' is an invalid flag."
        "\nCommands:"
        "\n\tmd5"
        "\n\tsha256"
        "\nFlags:"
        "\n\t-p -q -r -s\n", error);
    }
    if (error_id == USAGE)
    {
        printf("%s", "usage: ft_ssl command [flags] [file/string]\n");
    }
    if (error_id == MALLOC_FAILED)
    {
        printf("%s", "ft_ssl : Error : Failed to allocate memory.\n");
    }
}