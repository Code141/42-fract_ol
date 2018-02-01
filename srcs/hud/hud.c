/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:21:30 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 12:21:59 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "ctx.h"

t_hud	*new_hud(void)
{
	t_hud	*hud;

	hud = (t_hud*)malloc(sizeof(t_hud));
	if (!hud)
		crash("Broken malloc");
	return (hud);
}

void	destroy_hud(t_hud *hud)
{
	free(hud->graphs[0]);
	free(hud->graphs[1]);
	free(hud);
}
