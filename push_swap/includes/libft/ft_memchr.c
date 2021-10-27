/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:14:58 by hfunctio          #+#    #+#             */
/*   Updated: 2021/05/31 11:35:40 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			*a;

	a = (unsigned char *)s;
	while (n--)
	{
		if (*a != (unsigned char)c)
			a++;
		else
			return (a);
	}
	return (NULL);
}
