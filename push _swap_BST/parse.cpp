#include "push_swap_BST.hpp"

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(s1);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	len;
	char			*res;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
		res[k++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		res[k++] = s2[j++];
	res[k] = '\0';
	return (res);
}