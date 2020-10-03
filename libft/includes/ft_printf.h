/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:32:20 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/25 21:14:27 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef PARAMETERS
#  define CONVERSIONS	"cspdiuxX%"
#  define NUMBERS		"0123456789"
#  define FLAGS			"-0.*"
#  define ALL			"cspdiuxX%-0.*123456789"
# endif

# include <stdarg.h>

typedef struct	s_struct
{
	int	pos;
	int	neg;
	int	zero;
	int	dot;
	int	precision;
	int	width;
	int	err;
	int	ret;
	int	star;
	int	starp;
	int	sign;
}				t_struct;

int				ft_printf(const char *format, ...)
__attribute__ ((format (printf,1,2)));
void			ft_format_read(t_struct *s, va_list ap, char *format);
void			ft_tracker(t_struct *flags, va_list ap, char *format);
void			char_convert(t_struct *s, va_list ap);
void			percent_convert(t_struct *s);
void			int_convert(t_struct *s, va_list ap);
void			ft_left_aligned_int(t_struct *s, char *str, int slen);
void			ft_right_aligned_int(t_struct *s, int slen);
void			ft_aux_zeros(t_struct *s, char *str, int slen);
void			str_convert(t_struct *s, va_list ap);
void			ft_right_aligned_s(t_struct *s, int slen);
void			ft_left_aligned_s(t_struct *s, int slen);
void			ptr_convert(t_struct *s, va_list ap);
void			right_aligned_ptr(t_struct *s, char *str, int plen);
void			left_aligned_ptr(t_struct *s, char *str, int plen);
void			udec_int_convert(t_struct *s, va_list ap);
void			ft_right_aligned_udec_int(t_struct *s, char *str, int slen);
void			ft_left_aligned_udec_int(t_struct *s, char *str, int slen);
void			hex_convert(t_struct *s, va_list ap, char *format);
void			ft_right_aligned_hex(t_struct *s, char *str, int slen);
void			ft_left_aligned_hex(t_struct *s, char *str, int slen);
void			ft_check_flags(t_struct *s, va_list ap, char *format);
void			ft_flags(t_struct *s, char *format);
void			ft_width(t_struct *s, char *format, va_list ap);
void			ft_precision(t_struct *s, char *format, va_list ap);
void			ft_check_flags(t_struct *s, va_list ap, char *format);
void			ft_struct_init(t_struct *s);
void			ft_struct_zero(t_struct *s);

#endif
