/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cl                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:59:33 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/03 18:00:03 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_struct.h>

__kernel void	luncher(__global t_fractol *fractol, __global int *r)
{
	t_pixel	pixel;

	pixel.width = get_global_size(0);
	pixel.height = get_global_size(1);
	pixel.x = get_global_id(0);
	pixel.y = get_global_id(1);
	pixel.index = pixel.x + (pixel.y * pixel.width);
	pixel.max_iter = fractol->max_iter;
	pixel.cr = (-(pixel.width / 2) + pixel.x) / fractol->zoom + fractol->x;
	pixel.ci = (-(pixel.height / 2) + pixel.y) / fractol->zoom + fractol->y;
	pixel.cr_custom = fractol->cr_custom;
	pixel.ci_custom = fractol->ci_custom;

	iterations(fractol->fractal, &pixel);
	pixel.pos = ((float)(pixel.iterations) / fractol->max_iter);
	r[pixel.index] = color(&pixel, fractol->color_indice);
}
