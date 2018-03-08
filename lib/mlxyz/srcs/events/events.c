/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:12 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 19:34:25 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events/events.h>

int		hooks(t_mlxyz *mlxyz)
{
	mlx_hook(mlxyz->screen->win, KEYPRESS, 0, &key_press, mlxyz->keyboard);
	mlx_hook(mlxyz->screen->win, KEYRELEASE, 0, &key_release, mlxyz->keyboard);
	mlx_hook(mlxyz->screen->win, MOUSEMOVE, 0, &mouse_move, mlxyz->mouse);
	mlx_hook(mlxyz->screen->win, MOUSEPRESS, 0, &button_press, mlxyz->mouse);
	mlx_hook(mlxyz->screen->win, MOUSERELEASE, 0, &button_release,
		mlxyz->mouse);
	mlx_loop_hook(mlxyz->mlx, &loop, mlxyz);
	return (1);
}
