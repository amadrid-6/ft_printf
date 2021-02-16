/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_page_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:12:50 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/08 10:39:24 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags_precision(va_list *args)
{
	int			precision;
	char		*dest;
	char		*str;

	precision = va_arg(*args, int);
	if ((str = va_arg(*args, char *)) == NULL)
		return (dest = ft_strdup("(null)"));
	dest = (char *)malloc(ft_abs(precision) + ft_strlen(str) + 1);
	if (precision - ft_strlen(str) >= 0)
		ft_strcpy(dest, str);
	else
		ft_strlcpy(dest, str, precision + 1);
	return (dest);
}

char	*flags_precision_noargs(va_list *args, int precision)
{
	char		*dest;
	char		*str;

	if ((str = va_arg(*args, char *)) == NULL)
		str = ft_strdup("(null)");
	dest = (char *)malloc(ft_abs(precision) + 1);
	if (precision - ft_strlen(str) >= 0)
		ft_strcpy(dest, str);
	else
		ft_strlcpy(dest, str, precision + 1);
	return (dest);
}

char	*flags_no_args(va_list *args, t_flags f, int numb, char c)
{
	int				k;
	int				num1;
	unsigned	int	num2;
	char			*dest;
	char			*str;

	dest = NULL;
	if (f.data == 1)
	{
		num1 = va_arg(*args, int);
		k = numb - len_n(num1);
		dest = ft_conver_num(k, c, f.just, num1);
	}
	else if (f.data == 2 || f.data == 3 || f.data == 5)
	{
		num2 = va_arg(*args, unsigned int);
		str = conver_unsig_int(f.data, num2);
		k = numb - ft_strlen(str);
		dest = ft_conver_str(k, c, f.just, str);
	}
	else if (f.data == 4 || f.data == 6 || f.data == 7 || f.data == 8)
		dest = flags_no_args_1(args, f, numb, c);
	return (dest);
}

char	*flags_no_args_1(va_list *args, t_flags f, int numb, char c)
{
	char	*str;
	char	*dest;
	int		k;

	dest = NULL;
	if (f.data == 4)
	{
		if ((str = va_arg(*args, char *)) == NULL)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
		k = numb - ft_strlen(str);
		dest = ft_conver_str(k, c, f.just, str);
	}
	else if (f.data == 6)
	{
		str = conver_ptr(va_arg(*args, unsigned long long));
		k = numb - ft_strlen(str);
		dest = ft_conver_str(k, c, f.just, str);
	}
	else if (f.data == 7)
		dest = ft_conver_char(numb - 1, c, f.just, va_arg(*args, int));
	else if (f.data == 8)
		dest = ft_conver_char(numb - 1, c, f.just, '%');
	return (dest);
}

char	*flags_prec_args(va_list *args, int data)
{
	char	*dest;
	char	*str;
	int		num1;
	int		width;

	width = va_arg(*args, int);
	dest = NULL;
	if (data == 1)
	{
		num1 = va_arg(*args, int);
		if (width < 0)
			dest = ft_conver_num(ft_abs(width) - len_n(num1), ' ', 'l', num1);
		else
			dest = ft_conver_num(ft_abs(width) - len_n(num1), '0', 'r', num1);
	}
	else if (data == 2 || data == 3 || data == 5)
	{
		str = conver_unsig_int(data, va_arg(*args, unsigned int));
		if (width < 0)
			dest = ft_conver_str(ft_abs(width) - ft_strlen(str), ' ', 'l', str);
		else
			dest = ft_conver_str(ft_abs(width) - ft_strlen(str), '0', 'r', str);
	}
	return (dest);
}
