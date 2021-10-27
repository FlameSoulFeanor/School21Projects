/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:57:51 by hfunctio          #+#    #+#             */
/*   Updated: 2021/04/29 00:11:07 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*bgn;
	t_list	*l;

	if (lst)
	{
		l = lst;
		bgn = ft_lstnew(f(l->content));
		if (!bgn)
			return (NULL);
		l = l->next;
		while (l)
		{
			new = ft_lstnew(f(l->content));
			if (!new)
			{
				ft_lstclear(&bgn, del);
				return (NULL);
			}
			ft_lstadd_back(&bgn, new);
			l = l->next;
		}
		return (bgn);
	}
	return (NULL);
}
