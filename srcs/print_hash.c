#include "../includes/ft_ssl.h"

/*
    Print each elements with their associated option.
*/

void print_file(char *hash, char *arg, int flag)
{
    if ((flag & FLAG_Q) != 0)
        printf("%s\n", hash);
    else if ((flag & FLAG_R) != 0)
        printf("%s %s\n", hash, arg);
    else
        printf("MD5 (%s) = %s\n", arg, hash);
}

void print_string(char *hash, char *arg, int flag)
{
    if ((flag & FLAG_Q) != 0)
        printf("%s\n", hash);
    else if ((flag & FLAG_R) != 0)
        printf("%s \"%s\"\n", hash, arg);
    else
        printf("MD5 (\"%s\") = %s\n", arg, hash);
}

char *find_new_line(char *str)
{
    size_t len_str = ft_strlen(str);
    size_t i = 0;
    char *new_str = malloc(sizeof(char) * len_str);
    if (!new_str)
    {
        handle_errors(MALLOC_FAILED, NULL, -1);
        return (NULL);
    }
    while (i < len_str - 1)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

void print_stdin(char *hash, char *arg, int flag)
{
    if ((flag & FLAG_Q) != 0
    && (flag & FLAG_P) != 0)
    {
        if (arg[ft_strlen(arg)] != '\n')
            arg = find_new_line(arg);
        printf("%s\n", arg);
        printf("%s\n", hash);
        free(arg);
    }
    else if ((flag & FLAG_Q) != 0)
        printf("%s\n", hash);
    else if ((flag & FLAG_P) != 0)
    {
        if (arg[ft_strlen(arg)] != '\n')
            arg = find_new_line(arg);
        printf("(\"%s\")= %s\n", arg, hash);  
        free(arg);  
    }
    else
        printf("(stdin)= %s\n", hash);
}