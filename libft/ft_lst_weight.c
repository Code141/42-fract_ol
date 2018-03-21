/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_weight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:21:02 by gelambin          #+#    #+#             */
/*   Updated: 2017/12/05 18:22:05 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lst_weight(t_list *alst)
{
	unsigned int weight;

	weight = 0;
	while (alst)
	{
		weight += alst->content_size;
		alst = alst->next;
	}
	return (weight);
}
