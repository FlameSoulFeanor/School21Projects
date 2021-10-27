/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:14:58 by hfunctio          #+#    #+#             */
/*   Updated: 2020/10/29 16:30:49 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			*a;
	int						i;

	a = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (*a != (unsigned char)c)
			a++;
		else
			return (a);
	}
	return (NULL);
}
