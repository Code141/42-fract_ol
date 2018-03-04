/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.cl                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:59:33 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/03 18:00:03 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	color(float pos, double c_indice)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (pos == 1)
		return (0xffffff);
//	if (pos == 0)
//		return (0xffffff);
	r = (255 *(1-pos)) * ((sinpi((pos + M_PI_F * 2 * c_indice) * 8) + 1) / 2);
	g = (255 *(1-pos)) * ((sinpi(pos * 6) + 1) / 2);
	b = (255 *(1-pos)) * (1 - ((sinpi(pos * 3 * c_indice) + 1) / 2));
	return ((r << 16) + (g << 8) + b);
}

__kernel void	luncher(__global t_fractol *fractol, __global int *r)
{
	int	width;
	int	height;
	int	x;
	int	y;
	int i;

	width = get_global_size(0);
	height = get_global_size(1);
	x = get_global_id(0);
	y = get_global_id(1);


	
	r[x + (y * width)] = 0;
	i = iterations(
			(-(width / 2) + x) / fractol->zoom + fractol->x,
			(-(height / 2) + y) / fractol->zoom + fractol->y,
			fractol,
			x,
			y,
			width,
			r);

	r[x + (y * width)] += color(	
		((float)(i)	/ fractol->max_iter), fractol->color_indice);


//	r[x + (y * width)] += (0x666666 * (i % 2));
}
