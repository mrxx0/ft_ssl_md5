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
    printf("Command %s is not valid\n", *argv);
    return FALSE;
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

bool parse_flags(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        if (ft_strlen(argv[i]) > 2)
        {
            int j = 1;
            while (argv[i][j])
            {
                if (check_flag(argv[i][j]) == FALSE)
                {
                    printf("Flags are KO : exiting\n");
                    return (FALSE);
                }
                else
                {
                    printf("Flags are OK : stocking\n");
                    // save the flag
                }
                j++;
            }
        }
        else
        {
            if (check_flag(argv[i][1]) == FALSE)
            {
                printf("Flag [%c] is KO : exiting\n", argv[i][1]);
                return (FALSE);
            }
            else
            {
                printf("Flag is OK : stocking\n");
                // save the flag
            }
        }
        i++;
    }
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
    if (parse_command(++argv) == FALSE)
    {
        return FALSE;
        //Handling errors with id code
    }
    parse_flags(argv);
    return TRUE;
}
