/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:12 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:33:57 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events/events.h>

int		hooks(t_ctx *ctx)
{
	mlx_hook(ctx->screen->win, KEYPRESS, 0, &key_press, ctx->keyboard);
	mlx_hook(ctx->screen->win, KEYRELEASE, 0, &key_release, ctx->keyboard);
	mlx_hook(ctx->screen->win, MOUSEMOVE, 0, &mouse_move, ctx->mouse);
	mlx_hook(ctx->screen->win, MOUSEPRESS, 0, &button_press, ctx->mouse);
	mlx_hook(ctx->screen->win, MOUSERELEASE, 0, &button_release, ctx->mouse);
	mlx_loop_hook(ctx->mlx, &loop, ctx);
	return (1);
}
