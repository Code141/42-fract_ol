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

typedef struct	s_fractol
{
	char		*fractal_name;
	int			fractal;
	int			render;
	int			max_iter;
	double		zoom;
	double		x;
	double		y;
	double		color_indice;
	double		cre;
	double		cim;
}				t_fractol;

unsigned int	color(float pos, double c_indice)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (pos == 1)
		return (0xffffff);
	if (pos == 0)
		return (0x000000);
	r = 255 * ((sinpi((pos + M_PI_F * 2 * c_indice) * 8) + 1) / 2);
	g = 255 * ((sinpi(pos * 6) + 1) / 2);
	b = 255 * (1 - ((sinpi(pos * 3 * c_indice) + 1) / 2));
	return ((r << 16) + (g << 8) + b);
}

unsigned int	mandelbrot(double c_r, double c_i, __global t_fractol *fractol)
{
	int		i;
	double	z_r;
	double	z_i;
	double	z_r_c;
	double	z_i_c;

	i = 0;
	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = (c_i + c_i) * c_r + c_i;
	z_r = z_r_c - z_i_c + c_r;
	while (z_r_c + z_i_c <= 4 && i < fractol->max_iter)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = (z_i + z_i) * z_r + c_i;
		z_r = z_r_c - z_i_c + c_r;
		i++;
	}
	return (i);
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
	i = mandelbrot(
			(-(width / 2) + x) / fractol->zoom + fractol->x,
			(-(height / 2) + y) / fractol->zoom + fractol->y,
			fractol);
	r[x + (y * width)] = color(
		((float)(i)	/ fractol->max_iter), fractol->color_indice);
}
