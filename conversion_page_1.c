/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_page_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:13:01 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/09 10:31:24 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

char	*swap(char *str)
{
	char	*temp;
	int		i;
	int		n;

	n = ft_strlen(str);
	i = 0;
	temp = (char *)malloc(sizeof(char) * n + 1);
	while (i < (n / 2))
	{
		temp[i] = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = temp[i];
		i++;
	}
	free(temp);
	return (str);
}

char	*conver_hex(unsigned int numb)
{
	char			*str;
	int				i;
	unsigned	int	k;

	if (numb == 0)
		return (str = ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (calc_digit(numb) + 1));
	i = 0;
	while (numb != 0)
	{
		k = numb % 16;
		if (k < 10)
			str[i++] = k + 48;
		else
			str[i++] = k + 55;
		numb = numb / 16;
	}
	str[i] = '\0';
	return (str);
}

char	*conver_unsig_int(int data, unsigned int numb)
{
	char	*dest;

	if (data == 2)
	{
		dest = conver_hex(numb);
		dest = swap(dest);
		dest = ft_tolower(dest);
	}
	else if (data == 3)
	{
		dest = conver_hex(numb);
		dest = swap(dest);
	}
	else if (data == 5)
		dest = ft_itoa_unsig(numb);
	else
		return (NULL);
	return (dest);
}

char	*conver_ptr(unsigned long long num)
{
	char				*str;
	int					i;
	unsigned long long	k;

	if (num == 0)
		return (ft_strdup("0x0"));
	i = calc_digit_hex(num) + 2;
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	while (num != 0)
	{
		k = num % 16;
		if (k < 10)
			str[--i] = k + 48;
		else
			str[--i] = k + 55;
		num = num / 16;
	}
	str[1] = 'x';
	str[0] = '0';
	return (ft_tolower(str));
}
