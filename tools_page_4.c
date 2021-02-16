/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_page_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:16:54 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/02 13:49:03 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		neg(const char *nptr, int k)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)nptr;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '+')
				k = 1;
			else if (str[i] == '-')
				k = -1;
			j++;
		}
		else if (str[i] > 47 && str[i] < 58)
			break ;
		i++;
	}
	if (j > 1)
		return (0);
	else
		return (k);
}

int		ft_atoi(const char *nptr)
{
	char	*str;
	int		i;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = neg(nptr, k + 1);
	str = (char *)nptr;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\t' || str[i] == \
		'\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		k = (k * 10) + (str[i] - '0');
		i++;
	}
	return (l * k);
}

char	*ft_strdup(const char *s)
{
	char			*s1;
	char			*s2;
	unsigned	int	i;
	int				k;

	k = 0;
	s2 = (char *)s;
	i = ft_strlen(s2);
	s1 = malloc(sizeof(char) * (i + 1));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s2[k] != '\0')
	{
		s1[k] = s2[k];
		k++;
	}
	s1[k] = '\0';
	return (s1);
}

int		ft_abs(int a)
{
	if (a < 0)
		a = a * (-1);
	return (a);
}

char	*ft_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
