/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_page_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:12:14 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/05 13:26:30 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conver_void(void *p0)
{
	char		*str;
	char		*dest;
	uintptr_t	p;

	if (p0 == NULL)
		return (ft_strdup("0x0"));
	p = (uintptr_t)p0;
	str = ft_strdup("0x");
	dest = conver_hex(p);
	dest = ft_tolower(dest);
	dest = ft_strjoin(str, dest);
	return (dest);
}

char	*flags_prec_void(int numb, int k, char *str)
{
	char	*dest;
	int		i;

	i = 2;
	dest = (char *)malloc(numb + ft_strlen(str) + 1);
	if (k <= 0)
		ft_strcpy(dest, str);
	else
	{
		dest[0] = '0';
		dest[1] = 'x';
		while (k != 0)
		{
			dest[i] = '0';
			k--;
			i++;
		}
		k = 2;
		while (k < ft_strlen(str))
			dest[i++] = str[k++];
		dest[i] = '\0';
	}
	free(str);
	return (dest);
}
