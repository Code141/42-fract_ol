/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 18:49:52 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	refresh_keyboard(t_ctx *ctx)
{
	if (ctx->keyboard->key[53])
		close_fdf(ctx);
}

void	refresh_mouse(t_ctx *ctx)
{
	int			delta_x;
	int			delta_y;

	if (ctx->mouse->button[4])
	{
		ctx->mouse->button[4] = 0;
	}
	if (ctx->mouse->button[5])
	{
		ctx->mouse->button[5] = 0;
	}
	if (ctx->mouse->button[1])
	{
		delta_x = ctx->mouse->last_x - ctx->mouse->x;
		delta_y = ctx->mouse->last_y - ctx->mouse->y;
		// Get u'r delta here
		ctx->mouse->last_x = ctx->mouse->x;
		ctx->mouse->last_y = ctx->mouse->y;
	}
}

void	refresh_input_devices(t_ctx *ctx)
{
	refresh_keyboard(ctx);
	refresh_mouse(ctx);
}

int		loop(t_ctx *ctx)
{
	refresh_stats(ctx->stats);
	ft_bzero(ctx->screen->canevas->data,
			ctx->screen->canevas->width * ctx->screen->canevas->height * 4);
	refresh_input_devices(ctx);
	//	render(ctx);
	draw_hud(ctx);
	mlx_put_image_to_window(ctx->mlx,
			ctx->screen->win, ctx->screen->canevas->id, 0, 0);
	return (1);
}
