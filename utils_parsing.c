#include "push_swap.h"


void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

long	ft_atoi(const char *nptr)
{
	int			i;
	int			m;
	long		result;

	m = 1;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		m *= -1;
		i++;
	}
	if (nptr[i] == 0)
		i++;
	while (ft_isdigit(nptr[i]))
	{
		if (result * 10 > 2147483647 || result * 10 * m < -2147483648)
			ft_error("Error\n");
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	if (nptr[i])
		ft_error("Error\n");
	return (result * m);
}

int	ft_isdigit(int c)
{
	if ((c < 48 || c > 57))
		return (0);
	else
		return (1);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *save, char *buff)
{
	int		len1;
	int		len2;
	char	*str;

	str = malloc(((ft_strlen(save) + ft_strlen(buff)) + 2) * sizeof(char));
	if (!str)
	{
		free(save);
		return (NULL);
	}
	len2 = 0;
	len1 = 0;
	while (save && save[len1] != '\0')
	{
		str[len1] = save[len1];
		len1++;
	}
	while (buff[len2] != '\0')
	{
		str[len1 + len2] = buff[len2];
		len2++;
	}
	str[len1 + len2] = ' ';
	str[len1 + len2 + 1] = '\0';
	free(save);
	return (str);
}

