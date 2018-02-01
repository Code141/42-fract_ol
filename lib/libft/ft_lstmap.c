/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:24:12 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/23 18:00:08 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *elem;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	if (!list)
		return (NULL);
	elem = list;
	while (lst->next)
	{
		elem->next = f(lst->next);
		if (!elem->next)
			return (NULL);
		elem = elem->next;
		lst = lst->next;
	}
	return (list);
}
