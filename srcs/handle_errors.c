#include "../includes/ft_ssl.h"

/*  
    Handling errors with specific id code.
*/

int handle_errors(int error_id, char *error, int cmd, t_ssl *ssl)
{
    char *cmd_str;
    if (cmd == MD5)
        cmd_str = "md5";
    else if (cmd == SHA256)
        cmd_str = "sha256";
    else if (cmd == SHA384)
        cmd_str = "sha384";
    else if (cmd == SHA512)
        cmd_str = "sha512";
    else
        cmd_str = NULL;
    if (error_id == COMMAND_ERR)
    {
        printf("ft_ssl: Error: '%s' is an invalid command."
        "\nCommands:"
        "\n\tmd5"
        "\n\tsha256"
        "\n\tsha384"
        "\n\tsha512"
        "\nFlags:"
        "\n\t-p -q -r -s\n", error);
        exit(EXIT_FAILURE);
    }
    if (error_id == FLAG_ERR)
    {
        printf("ft_ssl: Error: '%s' is an invalid flag."
        "\nCommands:"
        "\n\tmd5"
        "\n\tsha256"
        "\n\tsha384"
        "\n\tsha512"
        "\nFlags:"
        "\n\t-p -q -r -s\n", error);
        exit(EXIT_FAILURE);
    }
    if (error_id == USAGE)
    {
        printf("%s", "usage: ft_ssl command [flags] [file/string]\n");
        exit(EXIT_FAILURE);
    }
    if (error_id == MALLOC_FAILED)
    {
        printf("%s", "ft_ssl : Error : Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    if (error_id == REPETED_FLAG)
    {
        printf("ft_ssl: Error: flag '%s' is already set.\n", error);
        exit(EXIT_FAILURE);
    }
    if (error_id == INVALID_FILE_DIRECTORY)
    {
        fprintf(stderr, "ft_ssl: %s: %s: No such file or directory\n",cmd_str, error);
        ssl->valid = 0;
        return (0);
    }
    if (error_id == MISSING_ARG)
    {
        printf("ft_ssl: -s flag requires an argument.\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}
