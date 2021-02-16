/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_page_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:05:37 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/11 13:11:09 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int			check_character(char *flags, int i)
{
	if (flags[i] == 'c' || flags[i] == 's' || flags[i] == 'p' || flags[i] \
		== 'd' || flags[i] == 'i' || flags[i] == 'u' || flags[i] == 'x' || \
		flags[i] == 'X' || flags[i] == '%')
		return (1);
	return (-1);
}

char		*make_flags(const char *format)
{
	unsigned	int	i;
	char			*str;

	str = (char *)malloc(10);
	i = 0;
	while (format[i] == '-' || format[i] == '.' || format[i] == '*' \
		|| format[i] == '0' || (format[i] > '0' && format[i] <= '9'))
	{
		str[i] = format[i];
		i++;
	}
	if ((format[i] == 'c' || format[i] == 's' || format[i] == 'p' || format[i] \
		== 'd' || format[i] == 'i' || format[i] == 'u' || format[i] == 'x' || \
		format[i] == 'X' || format[i] == '%'))
	{
		str[i] = format[i];
		str[++i] = '\0';
		return (str);
	}
	return (NULL);
}

int			read_conv(char *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while ((data[i] >= '0' && data[i] <= '9') || data[i] == '-' || \
		data[i] == '.' || data[i] == '*')
		i++;
	if (data[i] == 'd' || data[i] == 'i')
		j = 1;
	else if (data[i] == 'x')
		j = 2;
	else if (data[i] == 'X')
		j = 3;
	else if (data[i] == 's')
		j = 4;
	else if (data[i] == 'u')
		j = 5;
	else if (data[i] == 'p')
		j = 6;
	else if (data[i] == 'c')
		j = 7;
	else if (data[i] == '%')
		j = 8;
	return (j);
}

t_flags		make_struct(char *flags)
{
	t_flags		info;
	int			data;

	data = read_conv(flags);
	info.flags = flags;
	info.data = data;
	info.just = 0;
	return (info);
}
