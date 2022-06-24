#include "../includes/ft_ssl.h"

/*
    Print each elements with their associated option.
*/

void print_file(char *hash, char *arg, int flag, int cmd)
{
    if ((flag & FLAG_Q) != 0)
        printf("%s\n", hash);
    else if ((flag & FLAG_R) != 0)
        printf("%s %s\n", hash, arg);
    else
    {
        if (cmd == MD5)
            printf("MD5 (%s) = %s\n", arg, hash);
        else if (cmd == SHA256)
            printf("SHA256 (%s) = %s\n", arg, hash);
        else if (cmd == SHA384)
            printf("SHA384 (%s) = %s\n", arg, hash);        
        else if (cmd == SHA512)
            printf("SHA512 (%s) = %s\n", arg, hash);
    }
}

void print_string(char *hash, char *arg, int flag, int cmd)
{
    if ((flag & FLAG_Q) != 0)
        printf("%s\n", hash);
    else if ((flag & FLAG_R) != 0)
        printf("%s \"%s\"\n", hash, arg);
    else
    {
        if (cmd == MD5)
            printf("MD5 (\"%s\") = %s\n", arg, hash);
        else if (cmd == SHA256)
            printf("SHA256 (\"%s\") = %s\n", arg, hash);
        else if (cmd == SHA384)
            printf("SHA384 (%s) = %s\n", arg, hash);
        else if (cmd == SHA512)
            printf("SHA512 (\"%s\") = %s\n", arg, hash);
    }
}

void print_stdin(char *hash, char *arg, int flag)
{
    if ((flag & FLAG_Q) != 0
    && (flag & FLAG_P) != 0)
        printf("%.*s\n%s\n", ft_strlen_nonl(arg), arg, hash);
    else if ((flag & FLAG_Q) != 0)
        printf("%s\n", hash);
    else if ((flag & FLAG_P) != 0)
        printf("(\"%.*s\")= %s\n",ft_strlen_nonl(arg), arg, hash);  
    else
        printf("(stdin)= %s\n", hash);
}