/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:08:14 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/21 14:21:28 by gelambin         ###   ########.fr       */
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
	mlxyz->mouse = new_mouse();
	mlxyz->keyboard = new_keyboard();
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
