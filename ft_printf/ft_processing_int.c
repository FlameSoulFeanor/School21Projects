/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:06:26 by hfunctio          #+#    #+#             */
/*   Updated: 2021/07/03 20:34:11 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_int(char *str, int nbr, t_flags flags)
{
	int count;

	count = 0;
	if (flags.acc >= 0 && nbr < 0 && nbr != -2147483648)
		ft_putchar('-');
	if (flags.acc >= 0)
		count += ft_processing_width(flags.acc - 1, ft_strlen(str) - 1, 1);
	count += ft_puts.
	tr(str, ft_strlen(str));
	return (count);
}

static int	ft_put_int(char *str, int nbr, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input_int(str, nbr, flags);
	if (flags.acc >= 0 && (size_t)flags.acc < ft_strlen(str))
		flags.acc = ft_strlen(str);
	if (flags.acc >= 0)
	{
		flags.width -= flags.acc;
		count += ft_processing_width(flags.width, 0, 0);
	}
	else
		count += ft_processing_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_input_int(str, nbr, flags);
	return (count);
}

int			ft_processing_int(int nbr, t_flags flags)
{
	int		count;
	int		i;
	char	*str;

	count = 0;
	i = nbr;
	if (flags.acc == 0 && nbr == 0)
	{
		count += ft_processing_width(flags.width, 0, 0);
		return (count);
	}
	if (nbr < 0 && (flags.acc >= 0 || flags.zero == 1) && i != -2147483648)
	{
		if (flags.acc <= -1 && flags.zero == 1)
			ft_putstr("-", 1);
		nbr *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	str = ft_itoa(nbr);
	count += ft_put_int(str, i, flags);
	free(str);
	return (count);
}
