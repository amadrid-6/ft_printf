/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_page_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:03:41 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/09 10:30:33 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_asterisk(va_list *args, t_flags f, int i)
{
	char	*dest;
	int		len_dest;
	int		width;

	if ((width = va_arg(*args, int)) < 0)
	{
		f.just = 'l';
		width = width * -1;
	}
	if (f.flags[i] == '.' && f.flags[i + 1] == '*')
		dest = flags_prec_width_args(args, f, width);
	else if (f.flags[i] == '.' && \
		(f.flags[i + 1] >= '0' && f.flags[i + 1] <= '9'))
		dest = flags_prec_width(args, f, width, i);
	else
		dest = flags_no_args(args, f, width, ' ');
	len_dest = ft_strlen(dest);
	print_out_str(dest);
	free(dest);
	return (len_dest);
}

int	first_flag(va_list *args, t_flags f)
{
	int	a;

	a = 0;
	f.just = 'r';
	if (f.flags[0] > '0' && f.flags[0] <= '9')
		a = flags_number(args, f);
	else if (f.flags[0] == '0')
		a = flags_zero(args, f);
	else if (f.flags[0] == '*')
		a = flags_asterisk(args, f, 1);
	else if (f.flags[0] == '.')
		a = flags_point(args, f, 1);
	return (a);
}

int	flags_justification(va_list *args, t_flags f)
{
	int	a;

	a = 0;
	if (f.flags[0] == '-')
	{
		f.just = 'l';
		if (f.flags[1] > '0' && f.flags[1] <= '9')
			a = flags_number(args, f);
		else if (f.flags[1] == '0')
			a = flags_number(args, f);
		else if (f.flags[1] == '*')
			a = flags_asterisk(args, f, 2);
		else if (f.flags[1] == '.')
		{
			f.just = 'r';
			a = flags_point(args, f, 2);
		}
	}
	else
		a = first_flag(args, f);
	return (a);
}

int	no_flags(int numb, va_list *args)
{
	int	a;

	a = 1;
	if (numb == 1)
	{
		a = va_arg(*args, int);
		print_out_nbr(a);
		a = len_n(a);
	}
	else if (numb == 2 || numb == 3 || numb == 5)
		a = print_clean(conver_unsig_int(numb, va_arg(*args, unsigned int)));
	else if (numb == 4)
		a = print_out_len(va_arg(*args, char *));
	else if (numb == 7)
		ft_putchar(va_arg(*args, int));
	else if (numb == 6)
		a = print_clean(conver_ptr(va_arg(*args, unsigned long long)));
	else if (numb == 8)
		write(1, "%", 1);
	return (a);
}

int	flags_yes_or_not(char *flags, va_list *args, int data)
{
	int		a;
	t_flags f;

	if (flags)
	{
		f = make_struct(flags);
		if (check_flags(flags) == 1)
			a = flags_justification(args, f);
		else if (check_flags(flags) == 2)
			a = no_flags(data, args);
		else if (check_flags(flags) == 3)
			a = no_flags(data, args);
		else
			return (-1);
	}
	else
		return (-1);
	return (a);
}
