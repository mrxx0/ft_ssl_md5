#include "../includes/ft_ssl.h"

/*
    Supposedly receiving the command here.
    If not receiving a valid command, returns false else save it and 
    returns true.
*/

bool parse_command(char **argv)
{
    if (ft_strcmp(argv[1], "md5") == 0)
    {
        // save
        return (TRUE);
    }
    else if (ft_strcmp(argv[1], "sha256") == 0)
    {
        // save
        return (TRUE);
    }
    handle_errors(COMMAND_ERR, argv[1]);
    printf("Command %s is not valid\n", argv[1]);
    return (FALSE);
}

/*
    -p, echo STDIN to STDOUT and append the checksum to STDOUT
    -q, quiet mode
    -r, reverse the format of the output.
    -s, print the sum of the given string
*/

bool check_flag(char c)
{
    if (c != 'p'
    && c != 'q'
    && c!= 'r'
    && c != 's')
        return (FALSE);
    else
        return (TRUE);
}

/* 
    ./ft_ssl COMMAND -X file
    If - alone -> error
    If -X OK but if wrong flag -> error
*/

bool parse_flags(char **argv)
{
    int i = 2;
    while (argv[i] && argv[i][0] == '-')
    {
        printf("argv[i] = %s\n", argv[i]);
            if (ft_strlen(argv[i]) > 2)
            {
                handle_errors(FLAG_ERR, argv[i]);
                return (FALSE);
            }
            if (check_flag(argv[i][1]) == FALSE)
            {
                handle_errors(FLAG_ERR, argv[i]);
                return (FALSE);
            }
            else
            {
                printf("Flags are OK : stocking\n");
                // check if 
                // save the flag
            }
        i++;
    }
    if (i == 1)
    {
        // save NO FLAG
        printf("%s\n", "NO FLAG");
    }
    return (TRUE);
}

/*
./ft_ssl COMMAND [flags] [file/string]
    - COMMAND : md5 sha256
    - flags :
                -p, echo STDIN to STDOUT and append the checksum to STDOUT
                -q, quiet mode
                -r, reverse the format of the output.
                -s, print the sum of the given string
*/

bool parsing(char **argv)
{
    if (parse_command(argv) == FALSE)
        return (FALSE);
    if (parse_flags(argv) == FALSE)
        return (FALSE);
    return (TRUE);
}