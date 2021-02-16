/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_page_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:08:08 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/09 10:29:32 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_out_str_len(char *dest, int numb)
{
	int		i;
	int		k;

	i = 0;
	k = numb;
	while (i < k)
	{
		write(1, &dest[i], 1);
		i++;
	}
	free(dest);
}

int		calc_digit_hex(unsigned long long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int		ft_strlen_clean(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	free(src);
	return (i);
}

int		print_clean(char *str)
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
	free(str);
	return (i);
}
