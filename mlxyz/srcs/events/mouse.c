/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:14 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events/mouse.h>
#include <events/s_mouse.h>
#include <core/core.h>

int		mouse_move(int x, int y, t_mlxyz *mlxyz)
{
	mlxyz->mouse->x = x;
	mlxyz->mouse->y = y;
	return (1);
}

int		button_press(int button, int x, int y, t_mlxyz *mlxyz)
{
	mouse_move(x, y, mlxyz);
	if (y >= 0)
	{
		mlxyz->mouse->button[button] = 1;
		mlxyz->mouse->last_x = x;
		mlxyz->mouse->last_y = y;
	}
	return (1);
}

int		button_release(int button, int x, int y, t_mlxyz *mlxyz)
{
	mouse_move(x, y, mlxyz);
	mlxyz->mouse->button[button] = 0;
	return (1);
}

t_mouse	*new_mouse(void)
{
	t_mouse	*mouse;

	mouse = (t_mouse*)malloc(sizeof(t_mouse));
	if (!mouse)
		mlxyz_crash("Broken malloc");
	ft_bzero(mouse, sizeof(t_mouse));
	return (mouse);
}

void	destroy_mouse(t_mouse *mouse)
{
	free(mouse);
}
