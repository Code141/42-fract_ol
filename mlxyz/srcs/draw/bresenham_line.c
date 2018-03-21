/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:56:24 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 19:18:28 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw/bresenham_line.h>

void	b_line1(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color_rgba color)
{
	int	dx;
	int dy;
	int	e;

	dx = (v2.x - v1.x);
	dy = (v2.y - v1.y);
	e = v2.x - v1.x;
	while (v1.x < v2.x)
	{
		put_pixel(canevas, v1.x, v1.y, color);
		e -= dy;
		if (e <= 0)
		{
			v1.y++;
			e += dx;
		}
		v1.x++;
	}
}

void	b_line2(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color_rgba color)
{
	int	dx;
	int dy;
	int	e;

	dx = (v2.x - v1.x);
	dy = (v2.y - v1.y);
	e = v2.y - v1.y;
	while (v1.y < v2.y)
	{
		put_pixel(canevas, v1.x, v1.y, color);
		e -= dx;
		if (e <= 0)
		{
			v1.x++;
			e += dy;
		}
		v1.y++;
	}
}

void	b_line3(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color_rgba color)
{
	int	dx;
	int dy;
	int	e;

	dx = (v2.x - v1.x);
	dy = (v1.y - v2.y);
	e = v2.x - v1.x;
	while (v1.x < v2.x)
	{
		put_pixel(canevas, v1.x, v1.y, color);
		e -= dy;
		if (e <= 0)
		{
			v1.y--;
			e += dx;
		}
		v1.x++;
	}
}

void	b_line4(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color_rgba color)
{
	int	dx;
	int dy;
	int	e;

	dx = (v2.x - v1.x);
	dy = (v1.y - v2.y);
	e = v2.y - v1.y;
	while (v1.y > v2.y)
	{
		put_pixel(canevas, v1.x, v1.y, color);
		e -= dx;
		if (e <= 0)
		{
			v1.x++;
			e += dy;
		}
		v1.y--;
	}
}

void	line(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color_rgba color)
{
	int	dx;
	int dy;

	if (v1.x > v2.x)
		swap_vect2(&v1, &v2);
	dx = (v2.x - v1.x);
	if (v1.y < v2.y)
	{
		dy = (v2.y - v1.y);
		if (dx > dy)
			b_line1(canevas, v1, v2, color);
		else
			b_line2(canevas, v1, v2, color);
	}
	else
	{
		dy = (v1.y - v2.y);
		if (dx > dy)
			b_line3(canevas, v1, v2, color);
		else
			b_line4(canevas, v1, v2, color);
	}
}
