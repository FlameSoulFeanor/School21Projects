/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:12:52 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/27 02:27:57 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_pointer(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += ft_putstr("0x", 2);
	if (flags.acc >= 0)
	{
		count += ft_processing_width(flags.acc, ft_strlen(pointer), 1);
		count += ft_putstr(pointer, flags.acc);
	}
	else
		count += ft_putstr(pointer, ft_strlen(pointer));
	return (count);
}

static int			ft_proccesing_pointer_width(t_flags flags)
{
	int		count;

	count = 0;
	if (flags.width >= 0 && flags.minus == 0)
	{
		count += ft_processing_width(flags.width - 2, 0, 0);
		count += ft_putstr("0x", 2);
	}
	else
	{
		count += ft_putstr("0x", 2);
		count += ft_processing_width(flags.width - 2, 0, 0);
	}
	return (count);
}

int			ft_processing_point(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.acc == 0 && !num)
	{
		count += ft_proccesing_pointer_width(flags);
		return (count);
	}
	p = ft_utl_base(num, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.acc < ft_strlen(p))
		flags.acc = ft_strlen(p);
	if (flags.minus == 1)
		count += ft_input_pointer(p, flags);
	count += ft_processing_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count += ft_input_pointer(p, flags);
	free(p);
	return (count);
}
