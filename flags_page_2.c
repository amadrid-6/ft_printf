/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_page_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:15:34 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/08 16:28:17 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags_number(va_list *args, t_flags f)
{
	char			*dest;
	int				numb;
	int				len_dest;
	int				i;

	i = 0;
	dest = NULL;
	if ((numb = ft_atoi(f.flags)) < 0)
		numb = numb * (-1);
	while (ft_isdigit(f.flags[i]) == 1 || f.flags[i] == '-')
		i++;
	if (f.flags[i] == '.')
		if (f.flags[i + 1] == '*')
			dest = flags_prec_width_args(args, f, numb);
		else
			dest = flags_prec_width(args, f, numb, i);
	else if (f.flags[i] == 'c')
		return (flags_char_numb(args, numb, f.just));
	else
		dest = flags_no_args(args, f, numb, ' ');
	len_dest = ft_strlen(dest);
	print_out_str(dest);
	free(dest);
	return (len_dest);
}

int		flags_zero(va_list *args, t_flags f)
{
	char			*dest;
	int				numb;
	int				len_dest;
	int				i;

	i = 0;
	dest = NULL;
	if ((numb = ft_atoi(f.flags)) < 0)
		numb = numb * (-1);
	if (f.flags[1] == '-')
	{
		numb = ft_atoi(&f.flags[2]);
		f.just = 'l';
	}
	while (ft_isdigit(f.flags[i]) == 1 || f.flags[i] == '-')
		i++;
	dest = flags_zero_1(args, f, numb, i);
	len_dest = ft_strlen(dest);
	print_out_str(dest);
	free(dest);
	return (len_dest);
}

char	*flags_zero_1(va_list *args, t_flags f, int numb, int i)
{
	char	*dest;
	t_flags flags;

	dest = NULL;
	if (f.flags[i] == '.')
	{
		if (f.flags[i + 1] == '*')
			dest = flags_prec_width_args(args, f, numb);
		else
			dest = flags_prec_width(args, f, numb, i);
	}
	else if (check_character(f.flags, i) == 1)
	{
		flags.just = 'r';
		flags.data = f.data;
		dest = flags_no_args(args, flags, numb, '0');
	}
	else if (f.flags[i] == '*')
		dest = flags_prec_args(args, f.data);
	return (dest);
}

int		flags_point(va_list *args, t_flags f, int k)
{
	char	*dest;
	int		len_dest;

	dest = NULL;
	dest = flags_point_1(args, f, k);
	len_dest = ft_strlen(dest);
	print_out_str(dest);
	free(dest);
	return (len_dest);
}

char	*flags_point_1(va_list *args, t_flags f, int k)
{
	char	*dest;
	int		numb;

	dest = NULL;
	if (f.flags[k] == '*')
	{
		if (f.data == 4)
			dest = flags_precision(args);
		else
			dest = flags_prec(args, f, va_arg(*args, int), '0');
	}
	else if (f.flags[k] >= '0' && f.flags[k] <= '9')
	{
		numb = ft_atoi(&f.flags[k]);
		if (f.data == 4)
			dest = flags_precision_noargs(args, numb);
		else
			dest = flags_prec(args, f, numb, '0');
	}
	else if (f.flags[k] == 's')
		dest = ft_strdup("");
	else if (check_character(f.flags, k) == 1)
		dest = flags_prec(args, f, 0, '0');
	return (dest);
}
