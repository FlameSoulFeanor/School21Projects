/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:32:27 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:30:10 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	sb = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sb)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sb[j] = s[i];
			j++;
		}
		i++;
	}
	sb[j] = '\0';
	return (sb);
}
