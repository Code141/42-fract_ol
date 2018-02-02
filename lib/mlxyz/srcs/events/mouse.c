/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:14 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:49:10 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events/mouse.h>
#include <ctx.h>

int		mouse_move(int x, int y, t_mouse *mouse)
{
	mouse->x = x;
	mouse->y = y;
	return (1);
}

int		button_press(int button, int x, int y, t_mouse *mouse)
{
	mouse_move(x, y, mouse);
	if (y >= 0)
	{
		mouse->button[button] = 1;
		mouse->last_x = x;
		mouse->last_y = y;
	}
	return (1);
}

int		button_release(int button, int x, int y, t_mouse *mouse)
{
	mouse_move(x, y, mouse);
	mouse->button[button] = 0;
	return (1);
}

t_mouse	*new_mouse(void)
{
	t_mouse	*mouse;

	mouse = (t_mouse*)malloc(sizeof(t_mouse));
	if (!mouse)
		crash("Broken malloc");
	ft_bzero(mouse, sizeof(t_mouse));
	return (mouse);
}

void	destroy_mouse(t_mouse *mouse)
{
	free(mouse);
}
