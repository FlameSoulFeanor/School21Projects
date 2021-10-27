/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:36:42 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:40:27 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (*dest && i < destsize)
	{
		i++;
		dest++;
	}
	dest_len = i;
	if (destsize != 0)
	{
		while (*src && i < destsize - 1)
		{
			i++;
			*dest = *src;
			dest++;
			src++;
		}
	}
	if (i < destsize)
		*dest = '\0';
	return (dest_len + src_len);
}
