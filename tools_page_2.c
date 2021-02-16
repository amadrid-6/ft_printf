/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_page_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:17:32 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/02 13:40:40 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_out_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_out_nbr(int n)
{
	if (n == -2147483648)
		return (print_out_str("-2147483648"));
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		print_out_nbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void	print_out_unsig(unsigned int n)
{
	if (n == 4294967295)
		return (print_out_str("4294967295"));
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		print_out_unsig(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	int				i;
	int				j;
	unsigned	int	k;
	unsigned	int	h;

	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	dest = (char *)malloc(i + j + 1);
	if (dest == 0 || ((s1 == 0) && (s2 == 0)))
		return (NULL);
	k = 0;
	h = 0;
	while (s1[k] != '\0')
	{
		dest[k] = s1[k];
		k++;
	}
	while (s2[h] != '\0')
		dest[k++] = s2[h++];
	dest[k] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *source)
{
	char	*start;

	start = dest;
	while (*source != '\0')
		*dest++ = *source++;
	*dest = '\0';
	return (start);
}
