/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:00:35 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/11 12:42:47 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	create_prin(char *str, int i, va_list *args)
{
	char	*flags;
	int		data;
	int		len;

	flags = make_flags(&str[++i]);
	data = read_conv(&str[i]);
	if ((len = flags_yes_or_not(flags, args, data)) == -1)
	{
		write(1, "%", 1);
		return (-1);
	}
	free(flags);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned	int	i;
	int				len;
	int				k;

	i = 0;
	k = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((len = create_prin((char *)format, i, &args)) != -1)
			{
				k = k + len - ft_strlen_clean(make_flags(&format[++i])) - 1;
				i = i + ft_strlen_clean(make_flags(&format[i])) - 1;
			}
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (k + i);
}
