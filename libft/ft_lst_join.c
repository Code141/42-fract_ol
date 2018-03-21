/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:55:06 by gelambin          #+#    #+#             */
/*   Updated: 2017/12/09 18:21:53 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lst_join(t_list *alst, t_list *blist)
{
	t_list			*new_lst;

	new_lst = (t_list*)malloc(sizeof(*new_lst));
	if (!new_lst)
		return (NULL);
	new_lst->content_size = alst->content_size + blist->content_size;
	new_lst->content = ft_memalloc(new_lst->content_size);
	if (!new_lst->content)
		return (NULL);
	ft_memcpy(new_lst->content, alst->content, alst->content_size);
	ft_memcpy(new_lst->content + alst->content_size,
			blist->content, blist->content_size);
	new_lst->content_size = alst->content_size + blist->content_size;
	return (new_lst);
}
