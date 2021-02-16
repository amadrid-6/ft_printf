/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:02:22 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/21 12:50:47 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	int				i;
	int				j;
	unsigned	int	k;
	unsigned	int	h;

	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	dest = (char *)malloc(i + j + 1);
	if (dest == 0 || ((s1 == 0) && (s2 == 0)))
		return (NULL);
	k = 0;
	h = 0;
	while (s1[k] != '\0')
	{
		dest[k] = s1[k];
		k++;
	}
	while (s2[h] != '\0')
		dest[k++] = s2[h++];
	dest[k] = '\0';
	return (dest);
}
