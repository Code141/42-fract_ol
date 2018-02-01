/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:42:38 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/22 20:27:28 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "pixel.h"

void	put_pixel(t_img *canevas, int x, int y, t_color_rgba color)
{
	if ((y < 0 || y >= canevas->height) || (x < 0 || x >= canevas->width))
		return ;
	if (((unsigned int*)canevas->data)[(y * canevas->width) + x] < color.hex)
		((unsigned int*)canevas->data)[(y * canevas->width) + x] = color.hex;
}

void	draw_point(t_img *canevas, t_vector2 v, int size, t_color_rgba color)
{
	int x;
	int y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			put_pixel(canevas, v.x + x - size / 2, v.y + y - size / 2, color);
			y++;
		}
		x++;
	}
}
