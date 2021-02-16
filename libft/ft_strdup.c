/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:02:10 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/17 16:38:09 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
