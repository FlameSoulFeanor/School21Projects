/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_unsgnd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:55:24 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/27 04:37:33 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsgnd_input(char *num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.acc >= 0)
		count += ft_processing_width(flags.acc - 1, ft_strlen(num) - 1, 1);
	count += ft_putstr(num, ft_strlen(num));
	return (count);
}

static int	ft_put_unsgnd(char *num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_unsgnd_input(num, flags);
	if (flags.acc >= 0 && (size_t)flags.acc < ft_strlen(num))
		flags.acc = ft_strlen(num);
	if (flags.acc >= 0)
	{
		flags.width -= flags.acc;
		count += ft_processing_width(flags.width, 0, 0);
	}
	else
		count += ft_processing_width(flags.width, ft_strlen(num), flags.zero);
	if (flags.minus == 0)
		count += ft_unsgnd_input(num, flags);
	return (count);
}

int			ft_processing_unsgnd(unsigned int nbr, t_flags flags)
{
	int		count;
	char	*num;

	count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.acc == 0 && nbr == 0)
	{
		count += ft_processing_width(flags.width, 0, 0);
		return (count);
	}
	num = ft_itoa_unsgd(nbr);
	count = ft_put_unsgnd(num, flags);
	free(num);
	return (count);
}
