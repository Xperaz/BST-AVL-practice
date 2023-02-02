#include  "push_swap_BST.hpp"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*res;

	res = (char *)s;
	i = 0;
	while (i < n)
	{
		res[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*call;
	size_t	memory;

	memory = count * size;
	call = (size_t *) malloc(memory);
	if (!call)
		return (NULL);
	ft_bzero(call, memory);
	return (call);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;
	size_t	len1;

	if (!s)
		return (NULL);
	len1 = ft_strlen((char *)s);
	if (start >= len1)
		return ((char *)ft_calloc(1, 1));
	if (len > len1)
		len = len1;
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (len > 0 && (start < len1))
	{
		res[j++] = s[i++];
		len--;
	}
	res[j] = '\0';
	return (res);
}

int	count_word(char *str, char delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == delim)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == delim && str[i + 1] != delim)
			count++;
		i++;
	}
	if (str[i - 1] != delim)
		count++;
	return (count);
}

int	word_len(char *str, char delim)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delim)
		i++;
	return (i);
}

char	**ft_free(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char *str, char delim)
{
	int		i;
	int		word_count;
	char	**res;
	int		j;

	if (!str)
		return (NULL);
	word_count = count_word(str, delim);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0' && word_count--)
	{
		while (str[i] == delim)
			i++;
		res[j++] = (ft_substr(str + i, 0, word_len(str + i, delim)));
		if (!res[j - 1])
			ft_free(res, j);
		i = i + word_len(str + i, delim);
	}
	res[j] = 0;
	return (res);
}