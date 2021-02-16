/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_page_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:39:54 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/08 13:35:44 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill(char *save, int numb, int len, char just)
{
	char	*dest;
	char	*str;

	str = ft_itoa(numb);
	dest = NULL;
	len = 0;
	if (just == 'r')
		dest = ft_strjoin(save, str);
	else if (just == 'l')
		dest = ft_strjoin(str, save);
	free(str);
	return (dest);
}

char	*ft_conver_num(int len, char c, char just, int numb)
{
	char	*save;
	char	*dest;
	int		i;

	i = 0;
	save = (char *)malloc(sizeof(char ) * (ft_abs(len) + 1));
	if (len > 0)
	{
		if (numb < 0 && c == '0')
		{
			save[i] = '-';
			i++;
			numb = (-1) * numb;
		}
		while (len-- != 0)
			save[i++] = c;
		save[i] = '\0';
		dest = ft_fill(save, numb, len, just);
	}
	else
		dest = ft_itoa(numb);
	free(save);
	return (dest);
}

char	*ft_conver_str(int len, char c, char just, char *str)
{
	char	*dest;
	char	*save;
	int		i;

	i = 0;
	dest = NULL;
	save = (char *)malloc(sizeof(char) * (ft_abs(len) + 1));
	if (len > 0)
	{
		while (len-- != 0)
		{
			save[i] = c;
			i++;
		}
		save[i] = '\0';
		if (just == 'r')
			dest = ft_strjoin(save, str);
		else if (just == 'l')
			dest = ft_strjoin(str, save);
	}
	else
		dest = ft_strdup(str);
	free(save);
	free(str);
	return (dest);
}

char	*ft_conver_char(int len, char c, char just, int numb)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_abs(len) + 3));
	if (len > 0)
	{
		while (len-- != 0)
		{
			dest[i] = c;
			i++;
		}
		if (just == 'r')
			dest[i] = numb;
		else if (just == 'l')
		{
			dest[i] = c;
			dest[0] = numb;
		}
		dest[i + 1] = '\0';
	}
	else
		dest[0] = numb;
	return (dest);
}

int		flags_char_numb(va_list *args, int numb, char just)
{
	char	*dest;
	int		num1;

	num1 = va_arg(*args, int);
	dest = NULL;
	if (num1 == '\0')
	{
		if (just == 'r')
			dest = ft_conver_char(numb - 1, ' ', 'r', num1);
		else if (just == 'l')
			dest = ft_conver_char(numb - 1, ' ', 'l', num1);
		print_out_str_len(dest, numb);
	}
	else
	{
		dest = ft_conver_char(numb - 1, ' ', just, num1);
		print_out_str(dest);
		free(dest);
	}
	return (numb);
}
