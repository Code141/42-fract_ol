/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:52:57 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 16:11:06 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlxyz.h>

int		close_fdf(t_mlxyz *mlxyz)
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
