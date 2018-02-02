/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:52:59 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:47:41 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw/draw_hud.h>

void	draw_graph(t_graph *graph, t_img *canevas)
{
	t_vector2		v1;
	t_vector2		v2;
	t_color_rgba	color;
	int				i;
	int				data;

	i = 0;
	color.hex = 0x000000;
	while (i < graph->length)
	{
		data = graph->data[i];
		data = (data > graph->height) ? graph->height : data;
		v1.x = graph->x + graph->length - i;
		v1.y = graph->y + graph->height - data;
		v2.x = graph->x + graph->length - i;
		v2.y = graph->y + graph->height;
		color = color_blend(&graph->color_min, &graph->color_max,
			(float)data / graph->height);
		line(canevas, v1, v2, color);
		i++;
	}
}

void	draw_hud(t_ctx *ctx)
{
	draw_graph(ctx->hud->graphs[0], ctx->screen->canevas);
	draw_graph(ctx->hud->graphs[1], ctx->screen->canevas);
}
