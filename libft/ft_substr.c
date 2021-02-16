/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:03:49 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/21 13:07:51 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	char			*s2;
	unsigned	int	i;
	unsigned	int	k;

	if (start >= (unsigned int)ft_strlen((char *)s))
	{
		s2 = (char *)malloc(1);
		s2[0] = '\0';
		return (s2);
	}
	s1 = (char *)s;
	s2 = (char *)malloc(len + 1);
	if (s2 == 0)
		return (NULL);
	i = start;
	k = 0;
	while (k < len && s1[i] != '\0')
	{
		s2[k] = s1[i];
		i++;
		k++;
	}
	s2[k] = '\0';
	return (s2);
}
