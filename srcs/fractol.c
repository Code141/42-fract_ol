/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:59:59 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/03 19:26:34 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>
#include <math.h>

void	fractol_color(t_mlxyz *mlxyz, int x, int y, int i)
{
	t_fractol		*fractol;
	unsigned int	color;
	t_img			*canevas;
	float			pos;

	fractol = mlxyz->app;
	pos = (float)i / (float)fractol->max_iter;
	canevas = mlxyz->screen->canevas;
	color = 0x00000;
	if (i == 0)
		color = 0xffffff;
	else
	{
		color += (unsigned int)(255 * ((sin(pos * PI + PI * 2) + 1) / 2)) << 16;
		color += (unsigned int)(255 * ((sin(pos * PI) + 1) / 2)) << 8;
		color += 0x0000ff * (1 - ((sin(pos * PI) + 1) / 2));
	}
	((unsigned int*)canevas->data)[(y * canevas->width) + x] = color;
}
