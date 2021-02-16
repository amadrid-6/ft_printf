/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:23:56 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/21 12:55:48 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned	int	ft_search(char *str, char *set)
{
	unsigned	int	i;
	int				j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				i++;
				j = 0;
				break ;
			}
			else
				j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	return (i);
}

static	unsigned	int	ft_searchr(char *str, char *set)
{
	unsigned	int	i;
	int				j;

	i = ft_strlen(str);
	j = 0;
	i--;
	while (str[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				i--;
				j = 0;
				break ;
			}
			else
				j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	return (i);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	unsigned	int	k;
	unsigned	int	j;
	unsigned	int	i;
	char			*dest;

	i = 0;
	k = ft_search((char *)s1, (char *)set);
	if (k == (unsigned int)ft_strlen((char *)s1))
	{
		dest = (char *)malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	j = ft_searchr((char *)s1, (char *)set);
	dest = (char *)malloc(j - k + 2);
	if (dest == NULL)
		return (NULL);
	while (k <= j)
		dest[i++] = s1[k++];
	dest[i] = '\0';
	return (dest);
}
