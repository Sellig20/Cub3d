
#include "../cub3d.h"

char	*free_join_bb(char *str, int count)
{
	while (count >= 0)
	{
		free(str);
		count--;
	}
	free(str);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	final = malloc(sizeof(char) * (ft_strlen_gnl(s1)
				+ (ft_strlen_gnl(s2)) + 1));
	if (!final)
	{
		dprintf(2, "RETURN FINAL STRJOIN\n");
		return (free_join_bb(final, i), NULL);
	}
	while (s1 && (char)s1[i])
	{
		final[i] = (char)s1[i];
		i++;
	}
	free(s1);
	while ((char)s2[j])
	{
		final[i] = (char)s2[j];
		i++;
		j++;
	}
	final[i] = '\0';
	return (final);
}
