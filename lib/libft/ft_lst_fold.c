/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_fold.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:18:42 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/13 06:46:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lst_fold(t_list *alst)
{
	void			*data;
	unsigned int	weight;
	t_list			*new;

	weight = ft_lst_weight(alst);
	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = (void*)malloc(weight);
	new->next = NULL;
	if (!new->content)
		return (NULL);
	new->content_size = weight;
	data = new->content;
	while (alst)
	{
		ft_memcpy(data, alst->content, alst->content_size);
		data = ((char*)data) + alst->content_size;
		alst = alst->next;
	}
	return (new);
}
