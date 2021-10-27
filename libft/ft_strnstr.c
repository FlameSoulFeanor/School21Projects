/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:26:55 by hfunctio          #+#    #+#             */
/*   Updated: 2020/11/26 21:01:03 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;
	size_t	j;

	i = 0;
	b = (char*)needle;
	if (*b == 0)
		return ((char*)haystack);
	while (*haystack != '\0' && i++ < len)
	{
		haystack++;
		if (*(haystack - 1) != *b)
			continue;
		a = (char*)haystack - 1;
		j = i - 1;
		while (i++ - 1 < len + 1)
			if (*b == 0)
				return ((char*)haystack - 1);
			else if (*a++ != *b++)
				break ;
		i = j;
		b = (char*)needle;
	}
	return (0);
}
