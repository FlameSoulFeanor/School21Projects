/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:44:38 by hfunctio          #+#    #+#             */
/*   Updated: 2021/07/03 16:50:18 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.acc = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

static int		ft_pars(const char *format, int i, t_flags *flags, va_list ap)
{
	while (format[i])
	{
		if (!ft_conversion(format[i]) && !ft_flag(format[i])
		&& !ft_isdigit(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '*')
			*flags = ft_flag_width(ap, *flags);
		if (format[i] == '.')
			i = ft_flag_dot(format, i, flags, ap);
		if (format[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (ft_isdigit(format[i]))
			*flags = ft_flag_digit(format[i], *flags);
		if (ft_conversion(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int		ft_parse_param(const char *format, va_list ap)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (format[i])
	{
		flags = ft_init_flags();
		if (!format[i])
			break ;
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		else if (format[i] == '%' && format[i + 1])
		{
			i = ft_pars(format, ++i, &flags, ap);
			if (ft_conversion(format[i]))
				count += ft_processing((char)flags.type, flags, ap);
			else if (format[i])
				count += ft_putchar(format[i]);
		}
		i++;
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	count = 0;
	va_start(ap, format);
	count += ft_parse_param(format, ap);
	va_end(ap);
	return (count);
}
