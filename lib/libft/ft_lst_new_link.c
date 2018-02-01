/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:08:44 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/23 15:57:18 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lst_new_link(void const *content)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->content = (void*)content;
	list->content_size = sizeof(*content);
	list->next = NULL;
	return (list);
}
