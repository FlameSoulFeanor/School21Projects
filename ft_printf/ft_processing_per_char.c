/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_per_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:17:57 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/15 17:13:10 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processing_char(char ar, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(ar);
	count = ft_processing_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(ar);
	return (count + 1);
}

int		ft_processing_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putstr("%", 1);
	count += ft_processing_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putstr("%", 1);
	return (count);
}
