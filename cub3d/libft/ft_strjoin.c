/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:52:43 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/28 23:40:57 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*a;
	size_t				lens1;
	size_t				lens2;
	size_t				i;
	size_t				j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!a)
		return (NULL);
	if (s1 && s2)
	{
		while (++i < lens1)
			a[i] = s1[i];
		while (j < lens2)
			a[i++] = s2[j++];
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
