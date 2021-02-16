/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_page_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:52:45 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/02 13:39:39 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned	int	i;
	unsigned	int	j;
	unsigned	int	len;

	j = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	if (i >= size)
		len = size - 1;
	else
		len = i;
	while (j < len)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

void		is_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*negative = 1;
	}
}

void		is_negative_unsig(unsigned int *n, int *negative)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*negative = 1;
	}
}

char		*ft_itoa(int n)
{
	char			*str;
	int				tmpn;
	int				len;
	int				negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmpn = n;
	len = 2;
	negative = 0;
	is_negative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_unsig(unsigned int n)
{
	char			*str;
	unsigned	int	tmpn;
	int				len;
	int				negative;

	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	tmpn = n;
	len = 2;
	negative = 0;
	is_negative_unsig(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
