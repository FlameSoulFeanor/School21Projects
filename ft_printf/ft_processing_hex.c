/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:54:18 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/27 02:17:11 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_hex(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.acc >= 0)
	{
		count += ft_processing_width(flags.acc - 1, ft_strlen(hex) - 1, 1);
	}
	count += ft_putstr(hex, ft_strlen(hex));
	return (count);
}

static int	ft_hex_put(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input_hex(hex, flags);
	if (flags.acc >= 0 && (size_t)flags.acc < ft_strlen(hex))
		flags.acc = ft_strlen(hex);
	if (flags.acc >= 0)
	{
		flags.width -= flags.acc;
		count += ft_processing_width(flags.width, 0, 0);
	}
	else
		count += ft_processing_width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		count += ft_input_hex(hex, flags);
	return (count);
}

int			ft_processing_hex(unsigned int nbr, int lc, t_flags flags)
{
	int		count;
	char	*hex;

	count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.acc == 0 && nbr == 0)
	{
		count += ft_processing_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_utl_base((unsigned long long)nbr, 16);
	if (lc == 1)
		hex = ft_str_tolower(hex);
	count += ft_hex_put(hex, flags);
	free(hex);
	return (count);
}
