/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:48:33 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/25 15:45:34 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag(int ar)
{
	return ((ar == '.') || (ar = '*') || (ar == '0') || (ar == '-'));
}

t_flags	ft_flag_digit(char ar, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (ar - 48);
	return (flags);
}

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flag_width(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int		ft_flag_dot(const char *format, int start, t_flags *flags, va_list ap)
{
	int i;

	i = start;
	i++;
	if (format[i] == '*')
	{
		flags->acc = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->acc = 0;
		while (ft_isdigit(format[i]))
		{
			flags->acc = (flags->acc * 10) + (format[i] - 48);
			i++;
		}
	}
	return (i);
}
