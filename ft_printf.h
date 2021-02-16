/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:00:12 by amadrid-          #+#    #+#             */
/*   Updated: 2021/02/09 10:29:55 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_flags
{
	int		data;
	char	*flags;
	char	just;
}				t_flags;

int				ft_printf(const char *format, ...);

int				ft_isdigit(int c);

int				print_clean(char *str);

int				ft_strlen(char *src);

int				ft_strlen_clean(char *src);

int				calc_digit(int a);

int				calc_digit_hex(unsigned long long num);

int				len_n(int a);

int				neg(const char *nptr, int k);

int				print_out_len(char *str);

int				ft_atoi(const char *nptr);

int				check_character(char *flags, int i);

int				read_conv(char *data);

int				check_flags_point(char *flags, int i);

int				check_flags_zero_1(char *flags, int i);

int				check_flags_zero_2(char	*flags, int i);

int				check_flags_numb(char *flags, int i);

int				check_flags_asterisk(char *flags, int i);

int				check_flags_just(char *flags);

int				check_flags(char *flags);

int				flags_char_numb(va_list *args, int numb, char just);

int				ft_abs(int a);

int				flags_point(va_list *args, t_flags f, int k);

int				flags_number(va_list *args, t_flags f);

int				flags_zero(va_list *args, t_flags f);

int				flags_asterisk(va_list *args, t_flags f, int i);

int				first_flag(va_list *args, t_flags f);

int				flags_justification(va_list *args, t_flags f);

int				no_flags(int numb, va_list *args);

int				flags_yes_or_not(char *flags, va_list *args, int data);

char			hex_digit(int v);

char			*flags_prec_void(int numb, int k, char *str);

char			*flags_prec(va_list *args, t_flags f, int numb, char c);

char			*flags_prec_1(va_list *args, t_flags f, int numb, char c);

char			*flags_prec_2(va_list *args, t_flags f, int numb, char c);

char			*flags_prec_args(va_list *args, int data);

char			*flags_prec_width_args(va_list *args, t_flags f, int numb);

char			*flags_prec_width(va_list *args, t_flags f, int numb, int i);

char			*flags_zero_1(va_list *args, t_flags f, int numb, int i);

char			*flags_point_1(va_list *args, t_flags f, int k);

char			*ft_fill(char *save, int numb, int len, char just);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strcpy(char *dest, char *source);

char			*ft_strdup(const char *s);

char			*ft_itoa(int n);

char			*ft_itoa_unsig(unsigned int n);

char			*ft_conver_num(int len, char c, char just, int numb);

char			*ft_conver_str(int len, char c, char just, char *str);

char			*ft_conver_char(int len, char c, char just, int numb);

char			*flags_no_args(va_list *args, t_flags f, int numb, char c);

char			*flags_no_args_1(va_list *args, t_flags f, int numb, char c);

char			*flags_width(va_list *args, int data, char just, char c);

char			*flags_precision(va_list *args);

char			*flags_precision_noargs(va_list *args, int precision);

char			*make_flags(const char *format);

char			*ft_tolower(char *str);

char			*ft_strlcat(char *dst, char *src, size_t size);

char			*conver_ptr(unsigned long long num);

char			*swap(char *str);

char			*conver_hex(unsigned int numb);

char			*conver_unsig_int(int data, unsigned int numb);

char			*conver_void(void *p0);

void			ft_putchar(char c);

void			print_out_nbr(int n);

void			print_out_unsig(unsigned int n);

void			print_out_str_len(char *dest, int numb);

void			print_out_str(char *str);

void			is_negative(int *n, int *negative);

void			is_negative_unsig(unsigned int *n, int *negative);

size_t			ft_strlcpy(char *dst, char *src, size_t size);

t_flags			make_struct(char *flags);

#endif
