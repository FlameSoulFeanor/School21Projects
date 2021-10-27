/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:09:28 by hfunctio          #+#    #+#             */
/*   Updated: 2020/10/30 15:26:08 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	char			*b;

	b = 0;
	a = (unsigned char)c;
	while (*s)
	{
		if (*s == a)
			b = (char*)s;
		s++;
	}
	if (*s == 0 && a == 0)
		b = (char*)s;
	return (b);
}
