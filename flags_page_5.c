/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_page_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:22:13 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/08 15:43:34 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags_prec_width(va_list *args, t_flags f, int numb, int i)
{
	char	*dest;
	int		numb2;
	t_flags	flags;

	numb2 = ft_atoi(&f.flags[++i]);
	if (f.data != 4)
	{
		flags.just = 'r';
		flags.data = f.data;
		dest = flags_prec(args, flags, numb2, '0');
	}
	else
		dest = flags_precision_noargs(args, numb2);
	dest = ft_conver_str(numb - ft_strlen(dest), ' ', f.just, dest);
	return (dest);
}

char	*flags_prec_width_args(va_list *args, t_flags f, int numb)
{
	char	*dest;
	int		numb2;
	t_flags	flags;

	numb2 = va_arg(*args, int);
	if (numb < 0)
		numb = numb * -1;
	if (f.data != 4)
	{
		flags.just = 'r';
		flags.data = f.data;
		dest = flags_prec(args, flags, numb2, '0');
	}
	else
		dest = flags_precision_noargs(args, numb2);
	dest = ft_conver_str(numb - ft_strlen(dest), ' ', f.just, dest);
	return (dest);
}

char	*flags_prec(va_list *args, t_flags f, int numb, char c)
{
	char			*dest;
	int				num1;
	int				k;

	dest = NULL;
	if (f.data == 1)
	{
		num1 = va_arg(*args, int);
		k = numb - calc_digit(num1);
		if (num1 == 0 && numb == 0)
			dest = ft_strdup("\0");
		else
			dest = ft_conver_num(k, c, f.just, num1);
	}
	else if (f.data == 2 || f.data == 3 || f.data == 5)
		dest = flags_prec_2(args, f, numb, c);
	else if (f.data == 6 || f.data == 4)
		dest = flags_prec_1(args, f, numb, c);
	else if (f.data == 8)
		dest = ft_conver_char(numb - 1, c, f.just, '%');
	else if (f.data == 7)
		dest = ft_conver_char(numb - 1, c, f.just, va_arg(*args, int));
	return (dest);
}

char	*flags_prec_1(va_list *args, t_flags f, int numb, char c)
{
	char	*dest;
	char	*str;
	int		k;

	dest = NULL;
	if (f.data == 4)
	{
		if ((str = va_arg(*args, char *)) == NULL)
			str = ft_strdup("(null)");
		k = numb - ft_strlen(str);
		dest = ft_conver_str(k, c, f.just, str);
	}
	else if (f.data == 6)
	{
		if (numb == 0)
			dest = ft_strdup("0x");
		else
		{
			str = conver_ptr(va_arg(*args, unsigned long long));
			k = numb - ft_strlen(str) + 2;
			dest = flags_prec_void(numb, k, str);
		}
	}
	return (dest);
}

char	*flags_prec_2(va_list *args, t_flags f, int numb, char c)
{
	unsigned	int	num2;
	int				k;
	char			*str;
	char			*dest;

	num2 = va_arg(*args, unsigned int);
	str = conver_unsig_int(f.data, num2);
	k = numb - ft_strlen(str);
	if (num2 == 0 && numb == 0)
	{
		dest = ft_strdup("\0");
		free(str);
	}
	else
		dest = ft_conver_str(k, c, f.just, str);
	return (dest);
}
