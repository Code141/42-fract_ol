/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:41 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:51:11 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H
# include <hud/stats.h>
# include <hud/graph.h>

typedef struct	s_hud
{
	t_graph	*graphs[2];
}				t_hud;

t_hud			*new_hud();
void			destroy_hud(t_hud *hud);

#endif
