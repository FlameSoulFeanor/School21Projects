/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:47:09 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/20 22:41:30 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	int	acc;
	int width;
	int zero;
	int minus;
	int type;
	int star;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_flag(int ar);
int				ft_flag_dot(const char *format, int start,
						t_flags *flags, va_list ap);
t_flags			ft_flag_width(va_list ap, t_flags flags);
t_flags			ft_flag_minus(t_flags flags);
t_flags			ft_flag_digit(char ar, t_flags flags);
int				ft_processing(int ar, t_flags flags, va_list ap);
int				ft_conversion(int ar);
int				ft_processing_width(int width, int minus, int zero);
char			*ft_utl_base(unsigned long long nbr, int base);
int				ft_processing_unsgnd(unsigned int nbr, t_flags flags);
int				ft_processing_str(char *ap, t_flags flags);
int				ft_processing_point(unsigned long long num, t_flags flags);
int				ft_processing_percent(t_flags flags);
int				ft_processing_char(char ar, t_flags flags);
int				ft_processing_int(int nbr, t_flags flags);
int				ft_processing_hex(unsigned int nbr, int lc, t_flags flags);

#endif
