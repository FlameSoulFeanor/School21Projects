/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:07:23 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/20 22:45:19 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.acc >= 0)
	{
		count += ft_processing_width(flags.acc, ft_strlen(str), 0);
		count += ft_putstr(str, flags.acc);
	}
	else
		count += ft_putstr(str, ft_strlen(str));
	return (count);
}

int			ft_processing_str(char *ap, t_flags flags)
{
	int count;

	count = 0;
	if (!ap)
		ap = "(null)";
	if (flags.acc >= 0 && (size_t)flags.acc > ft_strlen(ap))
		flags.acc = ft_strlen(ap);
	if (flags.minus == 1)
		count += ft_input(ap, flags);
	if (flags.acc >= 0)
		count += ft_processing_width(flags.width, flags.acc, 0);
	else
		count += ft_processing_width(flags.width, ft_strlen(ap), 0);
	if (flags.minus == 0)
		count += ft_input(ap, flags);
	return (count);
}
