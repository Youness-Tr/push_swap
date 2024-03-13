/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:51:47 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/13 17:51:35 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
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

long	ft_atoi(char *nptr, long res, int i)
{
	int	sign;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (nptr[i] == 0)
		i++;
	while (ft_isdigit(nptr[i]))
	{
		if (res * 10 + nptr[i] - 48 > INT_MAX || res * 10 * sign < INT_MIN)
			ft_error("Error\n");
		res *= 10;
		res += nptr[i] - 48;
		i++;
	}
	if (nptr[i])
		ft_error("Error\n");
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if ((c < 48 || c > 57))
		return (0);
	else
		return (1);
}

char	*ft_strjoin_p(char *save, char *buff)
{
	int		len1;
	int		len2;
	char	*str;

	str = malloc(((ft_strlen(save) + ft_strlen(buff)) + 2) * sizeof(char));
	if (!str)
		return (NULL);
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
