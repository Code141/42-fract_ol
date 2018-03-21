/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:36 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:50:55 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H
# include <stdlib.h>
# include <libft.h>
# include <math/vector.h>
# include <color/color.h>
# include <screen/screen.h>
# include <hud/stats.h>

typedef struct	s_graph
{
	int				height;
	int				length;
	int				x;
	int				y;
	t_color_rgba	color_min;
	t_color_rgba	color_max;
	int				*data;
}				t_graph;

t_graph			*new_graph(int length, int height, int *data);

#endif
