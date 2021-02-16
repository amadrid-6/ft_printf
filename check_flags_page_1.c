/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_page_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:59:28 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/08 10:48:53 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags_point(char *flags, int i)
{
	int	k;

	k = 0;
	if (flags[i] >= '0' && flags[i] <= '9')
	{
		while (flags[i + k] >= '0' && flags[i + k] <= '9')
			k++;
		if (flags[i + k] != 'c' && (check_character(flags, i + k) == 1))
			return (1);
	}
	else if (flags[i] == '*')
	{
		if (flags[i + 1] != 'c' && (check_character(flags, i + 1) == 1))
			return (1);
	}
	else if (check_character(flags, i) == 1)
		return (1);
	return (-1);
}

int	check_flags_zero_1(char *flags, int i)
{
	int	k;

	k = 0;
	if (flags[i] >= '0' && flags[i] <= '9')
	{
		while (flags[i + k] >= '0' && flags[i + k] <= '9')
			k++;
		if ((flags[i + k] != 'c' && flags[i + k] != 'p') \
			&& (check_character(flags, i + k) == 1))
			return (1);
		else if (flags[i + k] == '.')
			return (1);
		else
			return (3);
	}
	else if (flags[i] == '*')
	{
		if ((flags[i + 1] != 's' && flags[i + 1] != 'c' && flags[i + 1] != 'p')\
			&& (check_character(flags, i + 1) == 1))
			return (1);
		else
			return (3);
	}
	return (-1);
}

int	check_flags_zero_2(char *flags, int i)
{
	if (flags[i] == '-')
		return (1);
	else if ((check_character(flags, i) == 1))
		return (1);
	else if (flags[i] == '.')
		return (check_flags_point(flags, i + 1));
	return (-1);
}

int	check_flags_asterisk(char *flags, int i)
{
	if (check_character(flags, i) == 1)
		return (1);
	else if (flags[i] == '.' && flags[i + 1] == '*')
		return (1);
	else if (flags[i] == '.' && (flags[i + 1] >= '0' && flags[i + 1] <= '9'))
		return (1);
	else if (flags[i] == '.' && (check_character(flags, i + 1) == 1))
		return (1);
	return (-1);
}

int	check_flags_numb(char *flags, int i)
{
	int	k;

	k = 0;
	if (flags[i] > '0' && flags[i] <= '9')
	{
		while (flags[i + k] >= '0' && flags[i + k] <= '9')
			k++;
		if (check_character(flags, i + k) == 1)
			return (1);
		else if (flags[i + k] == '.')
		{
			if (check_character(flags, i + k + 1) == 1)
				return (1);
			else if (flags[i + k + 1] >= '0' && flags[i + k + 1] <= '9')
			{
				while (flags[i + k + 1] >= '0' && flags[i + k + 1] <= '9')
					k++;
				if (check_character(flags, i + k + 1) == 1)
					return (1);
			}
			else if (flags[i + k + 1] == '*')
				return (1);
		}
	}
	return (-1);
}
