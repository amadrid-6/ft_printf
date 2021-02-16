/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:37:45 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/17 12:15:30 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)s;
	j = ft_strlen(str);
	i = 0;
	while (i <= j)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
