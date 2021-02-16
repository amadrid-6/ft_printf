/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_page_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:27:55 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/02 13:41:56 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int		len_n(int a)
{
	int	j;

	j = 0;
	if (a <= 0)
		j++;
	while (a != 0)
	{
		a = a / 10;
		j++;
	}
	return (j);
}

int		calc_digit(int a)
{
	int	j;

	j = 0;
	if (a == 0)
		return (j = 1);
	while (a != 0)
	{
		a = a / 10;
		j++;
	}
	return (j);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		print_out_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
