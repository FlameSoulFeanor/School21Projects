/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:57:51 by hfunctio          #+#    #+#             */
/*   Updated: 2020/11/05 21:10:23 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*bgn;
	t_list	*l;

	if (lst)
	{
		l = lst;
		if (!(bgn = ft_lstnew(f(l->content))))
			return (NULL);
		l = l->next;
		while (l)
		{
			if (!(new = ft_lstnew(f(l->content))))
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
