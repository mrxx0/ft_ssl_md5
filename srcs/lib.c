#include "../includes/ft_ssl.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(s1);
	dest = NULL;
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

char		*strnjoins(char *s1, char *s2, size_t len1, size_t len2)
{
	size_t	i;
	char	*output;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!(output = (char *)ft_memalloc(sizeof(char) * (len1 + len2 + 1))))
	{
		ft_strdel(&s1);
		return (NULL);
	}
	while (i < len1 || i < len2)
	{
		if (i < len1)
			output[i] = s1[i];
		if (i < len2)
			output[i + len1] = s2[i];
		i++;
	}
	ft_strdel(&s1);
	return (output);
}


void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*b_cpy;

	b_cpy = (char *)b;
	i = 0;
	while (i < n)
	{
		b_cpy[i] = (unsigned char)c;
		i++;
	}
	return (b_cpy);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memalloc(size_t size)
{
	char *mem;

	if (!(mem = malloc(sizeof(char) * size)))
		return (NULL);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}

size_t	ft_strlen(const char *s)
{
	int count;

	if (s)
	{
		count = 0;
		while (s[count])
			count++;
		return (count);
	}
	return (0);
}