/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:52:57 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 18:40:11 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ctx.h"

int		close_fdf(t_ctx *ctx)
{
	if (ctx->screen)
	{
		if (ctx->screen->canevas)
			free(ctx->screen->canevas);
		mlx_destroy_window(ctx->mlx, ctx->screen->win);
		free(ctx->screen);
	}
	destroy_hud(ctx->hud);
	destroy_camera(ctx->camera);
	destroy_mouse(ctx->mouse);
	destroy_keyboard(ctx->keyboard);
	free(ctx->stats);
	free(ctx);
	ft_putstr("Exit.");
	exit(0);
}

void	crash(char *str)
{
	ft_putendl("========== CRASH ==========");
	ft_putendl(str);
	ft_putendl("===========================");
	exit(1);
}

void	show_usage(void)
{
	ft_putstr("usage: fdf");
	ft_putstr(" target_file\n");
	exit(0);
}
