/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:52:13 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 00:11:47 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_number(int number)
{
	int	i;

	i = 0;
	if (number < 0)
		i++;
	if (number == 0)
		return (i = 1);
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;
	int		sign;

	sign = 1;
	i = len_of_number(n);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	dst[i--] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		sign = -1;
	}
	while (n != 0)
	{
		dst[i] = sign * (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}
