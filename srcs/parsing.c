#include "../includes/ft_ssl.h"

/*
    Supposedly receiving the command here.
    If not receiving a valid command, returns false else save it and 
    returns true.
*/

bool parse_command(char **argv, t_ssl *ssl)
{
    if (ft_strcmp(argv[1], "md5") == 0)
    {
        ssl->cmd = MD5;
        return (TRUE);
    }
    else if (ft_strcmp(argv[1], "sha256") == 0)
    {
        ssl->cmd = SHA256;
        return (TRUE);
    }
    ssl->cmd = 0;
    handle_errors(COMMAND_ERR, argv[1]);
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

bool stock_flag(char c, t_ssl *ssl)
{
    if (c == 'p')
    {
        if ((ssl->flag & FLAG_P) == 0)
            ssl->flag |= FLAG_P;
        else
            return (FALSE);
    }
    if (c == 'q')
    {
        if ((ssl->flag & FLAG_Q) == 0)
            ssl->flag |= FLAG_Q;
        else
            return (FALSE);
    }
    if (c == 'r')
    {
        if ((ssl->flag & FLAG_R) == 0)
            ssl->flag |= FLAG_R;
        else
            return (FALSE);
    }
    if (c == 's')
    {
        if ((ssl->flag & FLAG_S) == 0)
            ssl->flag |= FLAG_S;
        else
            return (FALSE);
    }
    return (TRUE);
}

/* 
    ./ft_ssl COMMAND -X file
    If - alone -> error
    If -X OK but if wrong flag -> error
*/

bool parse_flags(char **argv, t_ssl	*ssl)
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
                if (stock_flag(argv[i][1], ssl) == FALSE)
                {
                    handle_errors(5, &argv[i][1]);
                    return (FALSE);
                }
                printf("Flags are OK : stocking\n");
            }
        i++;
    }
    if (i == 2)
    {
        ssl->flag |= NO_FLAG;
        printf("%s\n", "NO FLAG");
    }
    ssl->offset = i;
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

bool parsing(char **argv, t_ssl	*ssl)
{
    if (parse_command(argv, ssl) == FALSE)
        return (FALSE);
    if (parse_flags(argv, ssl) == FALSE)
        return (FALSE);
    return (TRUE);
}