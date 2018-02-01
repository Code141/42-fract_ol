/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:05:36 by gelambin          #+#    #+#             */
/*   Updated: 2017/12/15 23:09:20 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lst_remove(t_list **alst, t_list *elem)
{
	t_list	*el;

	if (!*alst || !elem)
		return (NULL);
	if (*alst == elem)
	{
		*alst = (*alst)->next;
		elem->next = NULL;
		return (elem);
	}
	el = *alst;
	while (el->next && el->next != elem)
		el = el->next;
	if (el->next == elem)
	{
		el->next = elem->next;
		elem->next = NULL;
		return (elem);
	}
	return (NULL);
}
