#include "../includes/ft_ssl.h"

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