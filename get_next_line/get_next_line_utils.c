/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:31:33 by hfunctio          #+#    #+#             */
/*   Updated: 2020/12/27 16:58:12 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char		*ft_strjoin(char const *s1, char const *s2)
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
	if (!(a = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1))))
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

char		*ft_strchr(const char *s, int c)
{
	char i;

	i = (char)c;
	while (*s)
	{
		if (*s == i)
			return ((char*)s);
		s++;
	}
	if (*s == 0 && i == 0)
		return ((char*)s);
	return (0);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(sb = (char *)malloc(sizeof(*s) * (len + 1))))
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

char		*ft_strdup(const char *s1)
{
	char		*s2;
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
		if (s1[i] != '\0')
		{
			s2[i] = s1[i];
			i++;
		}
	s2[i] = '\0';
	return (s2);
}
