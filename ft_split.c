#include "pipex.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char *s, char set)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	if (!s)
		return (NULL);
	res = malloc((count_words(s, set) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != set && start < 0)
			start = i;
		else if ((s[i] == set || s[i + 1] == '\0') && start >= 0)
		{
			if (s[i] == set)
				res[j++] = ft_substr(s, start, i);
			else
				res[j++] = ft_substr(s, start, i + 1);
			start = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
