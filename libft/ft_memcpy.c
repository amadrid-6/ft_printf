/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:00:55 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/17 15:50:38 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned	int	i;
	char			*s;
	char			*p;

	if (src == 0 && dest == 0)
		return (NULL);
	s = (char *)src;
	p = dest;
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
