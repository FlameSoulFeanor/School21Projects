/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:50:04 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/27 04:35:33 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_conversion(int ar)
{
	return ((ar == 'c') || (ar == 's') || (ar == 'p') || (ar == 'd') ||
	(ar == 'i') || (ar == 'u') || (ar == 'x') || (ar == 'X') || (ar == '%'));
}

int			ft_processing(int ar, t_flags flags, va_list ap)
{
	int	count;

	count = 0;
	if (ar == '%')
		count += ft_processing_percent(flags);
	else if (ar == 'c')
		count = ft_processing_char(va_arg(ap, int), flags);
	else if (ar == 's')
		count = ft_processing_str(va_arg(ap, char *), flags);
	else if (ar == 'p')
		count = ft_processing_point(va_arg(ap, unsigned long long), flags);
	else if ((ar == 'd') || (ar == 'i'))
		count = ft_processing_int(va_arg(ap, int), flags);
	else if (ar == 'x')
		count += ft_processing_hex(va_arg(ap, unsigned int), 1, flags);
	else if (ar == 'X')
		count += ft_processing_hex(va_arg(ap, unsigned int), 0, flags);
	else if (ar == 'u')
	{
		count += ft_processing_unsgnd((unsigned long)
		va_arg(ap, unsigned long), flags);
	}
	return (count);
}
