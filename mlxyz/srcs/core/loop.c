/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:08:14 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/16 19:35:56 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/core.h>

void	mlxyz_run_loop(t_mlxyz *mlxyz, void (*app_loop)(t_mlxyz *mlxyz))
{
	mlxyz->loop_app = app_loop;
	mlx_loop(mlxyz->mlx);
}

int		mlxyz_loop(void *ptr)
{
	t_mlxyz	*mlxyz;

	mlxyz = (t_mlxyz*)ptr;
	refresh_stats(mlxyz->stats);
	mlxyz->loop_app(mlxyz);
	return (1);
}
