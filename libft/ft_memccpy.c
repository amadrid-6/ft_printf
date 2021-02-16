/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:00:26 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/21 12:41:54 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, int size)
{
	int					i;
	unsigned	char	*d;
	unsigned	char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		if (s[i] != (unsigned char)c)
			d[i] = s[i];
		else
		{
			d[i] = s[i];
			return (&d[i + 1]);
		}
		i++;
	}
	return (NULL);
}
