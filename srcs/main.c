/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:45:35 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlxyz.h>

t_ctx		*ctx_init(void)
{
	t_ctx	*ctx;

	ctx = (t_ctx*)malloc(sizeof(t_ctx));
	if (!ctx)
		crash("Broken malloc");
	ft_bzero(ctx, sizeof(t_ctx));
	ctx->mlx = mlx_init();
	if (!ctx->mlx)
		close_fdf(ctx);
	ctx->screen = new_screen(ctx->mlx, 1024, 786);
	ctx->stats = new_stats();
	ctx->hud = new_hud();
	ctx->hud->graphs[0] = new_graph(100, 60, ctx->stats->fps);
	ctx->hud->graphs[1] = new_graph(100, 60, ctx->stats->ms);
	ctx->hud->graphs[1]->color_min.hex = 0x00ffff;
	ctx->hud->graphs[1]->color_max.hex = 0xff0000;
	ctx->hud->graphs[1]->x = 102;
	ctx->camera = new_camera(TO_RAD(120), 10, 100);
	ctx->camera->pos.z = 0;
	ctx->mouse = new_mouse();
	ctx->keyboard = new_keyboard();
	hooks(ctx);
	return (ctx);
}

int			main(int argc, char **argv)
{
	t_ctx		*ctx;

	argc--;
	argv++;

//	if (argc != 1)
//		show_usage();
	ctx = ctx_init();
	mlx_loop(ctx->mlx);
	return (0);
}
