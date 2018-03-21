/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:12 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/21 14:17:53 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events/events.h>

int		hooks(t_mlxyz *mlxyz)
{
	mlx_hook(mlxyz->screen->win, KEYPRESS, 0, &mlxyz_key_press, mlxyz);
	mlx_hook(mlxyz->screen->win, KEYRELEASE, 0, &mlxyz_key_release, mlxyz);
	mlx_hook(mlxyz->screen->win, MOUSEMOVE, 0, &mouse_move, mlxyz);
	mlx_hook(mlxyz->screen->win, MOUSEPRESS, 0, &button_press, mlxyz);
	mlx_hook(mlxyz->screen->win, MOUSERELEASE, 0, &button_release,
		mlxyz);
	mlx_loop_hook(mlxyz->mlx, &mlxyz_loop, mlxyz);
	return (1);
}
