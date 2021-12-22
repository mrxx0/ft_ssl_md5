#include "../includes/ft_ssl.h"

/*
    Supposedly receiving the command here.
    If not receiving a valid command, returns false else save it and 
    returns true.
*/

bool parse_command(char **argv)
{
    if (ft_strcmp(*argv, "md5") == 0)
    {
        // save
        return TRUE;
    }
    else if (ft_strcmp(*argv, "sha256") == 0)
    {
        // save
        return TRUE;
    }
    return FALSE;
}

/*
    -p, echo STDIN to STDOUT and append the checksum to STDOUT
    -q, quiet mode
    -r, reverse the format of the output.
    -s, print the sum of the given string
*/

bool parse_flags(char **argv)
{
    (void)argv;
    return TRUE;
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
    parse_command(++argv);
    parse_flags(argv);
    return TRUE;
}
