/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_page_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:15:43 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/02 13:19:03 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags_zero(char *flags, int i)
{
	if ((flags[i] >= '0' && flags[i] <= '9') || flags[i] == '*')
		return (check_flags_zero_1(flags, i));
	else
		return (check_flags_zero_2(flags, 1));
}

int	check_flags_just(char *flags)
{
	if (flags[1] == '.')
		return (check_flags_point(flags, 2));
	else if (flags[1] == '*')
		return (check_flags_asterisk(flags, 2));
	else if (flags[1] > '0' && flags[1] <= '9')
		return (check_flags_numb(flags, 1));
	else if (flags[1] == '0')
		return (check_flags_zero(flags, 2));
	else if (check_character(flags, 1) == 1)
		return (2);
	else
		return (-1);
}

int	check_flags(char *flags)
{
	if (flags[0] == '.')
		return (check_flags_point(flags, 1));
	else if (flags[0] == '0')
		return (check_flags_zero(flags, 1));
	else if (flags[0] == '*')
		return (check_flags_asterisk(flags, 1));
	else if (flags[0] > '0' && flags[0] <= '9')
		return (check_flags_numb(flags, 0));
	else if (flags[0] == '-')
		return (check_flags_just(flags));
	else if (check_character(flags, 0))
		return (2);
	else
		return (-1);
}
