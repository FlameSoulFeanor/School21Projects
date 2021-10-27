/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:20:11 by hfunctio          #+#    #+#             */
/*   Updated: 2020/11/04 17:40:30 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(a = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	else
	{
		while (s[i])
		{
			a[i] = f(i, s[i]);
			i++;
		}
		a[i] = '\0';
	}
	return (a);
}
