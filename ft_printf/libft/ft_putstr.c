/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:08:54 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/14 18:09:15 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *ap, int prec)
{
	int count;

	count = 0;
	while (ap[count] && count < prec)
	{
		ft_putchar(ap[count]);
		count++;
	}
	return (count);
}
