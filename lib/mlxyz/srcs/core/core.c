/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:08:14 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/05 19:10:51 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/core.h>
#include <events/events.h>

t_mlxyz	*mlxyz_init(void)
{
	t_mlxyz	*mlxyz;

	mlxyz = (t_mlxyz*)malloc(sizeof(t_mlxyz));
	if (!mlxyz)
		mlxyz_crash("Broken malloc");
	ft_bzero(mlxyz, sizeof(t_mlxyz));

	mlxyz->mlx = mlx_init();

	if (!mlxyz->mlx)
		mlxyz_close(mlxyz);

	mlxyz->screen = new_screen(mlxyz->mlx, 1024, 786);

	mlxyz->stats = new_stats();

	mlxyz->hud = new_hud();
	mlxyz->hud->graphs[0] = new_graph(100, 60, mlxyz->stats->fps);
	mlxyz->hud->graphs[1] = new_graph(100, 60, mlxyz->stats->ms);
	mlxyz->hud->graphs[1]->color_min.hex = 0x00ffff;
	mlxyz->hud->graphs[1]->color_max.hex = 0xff0000;
	mlxyz->hud->graphs[1]->x = 102;

	mlxyz->camera = new_camera(TO_RAD(120), 10, 100);
	mlxyz->camera->pos.z = 0;

	mlxyz->mouse = new_mouse();

	mlxyz->keyboard = new_keyboard();

	mlxyz->opencl = init_opencl();

	hooks(mlxyz);
	return (mlxyz);
}

void	mlxyz_close(t_mlxyz *mlxyz)
{
	if (mlxyz->screen)
	{
		if (mlxyz->screen->canevas)
			free(mlxyz->screen->canevas);
		mlx_destroy_window(mlxyz->mlx, mlxyz->screen->win);
		free(mlxyz->screen);
	}
	destroy_hud(mlxyz->hud);
	destroy_camera(mlxyz->camera);
	destroy_mouse(mlxyz->mouse);
	destroy_keyboard(mlxyz->keyboard);
	free(mlxyz->stats);
	free(mlxyz);
}

void	mlxyz_crash(char *str)
{
	ft_putendl("========== CRASH ==========");
	ft_putendl(str);
	ft_putendl("===========================");
	exit(1);
}
