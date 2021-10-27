/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:01:02 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:47:27 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!len || dest == src)
		return (dest);
	if ((unsigned char *)dest < (unsigned char *)src)
	{
		while (i < len)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			*((unsigned char *)dest + (len - 1))
				= *((unsigned char *)src + (len - 1));
			len--;
		}
	}
	return (dest);
}
