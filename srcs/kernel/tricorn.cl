/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.cl                                         :+:      :+:    :+:   */
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
	if (pos == 1)
		return (0xffffff);
	return (((unsigned int)(255 * ((sinpi((pos + M_PI_F * 2 * c_indice) * 8)
			+ 1) / 2)) << 16)
		+ ((unsigned int)(255 * ((sinpi(pos * 6) + 1) / 2)) << 8)
		+ (0x0000ff * (1 - ((sinpi(pos * 3 * c_indice) + 1) / 2))));
}

unsigned int	mandelbrot(double c_r, double c_i, int max_iter)
{
	double	z_r;
	double	z_i;
	double	z_r_c;
	double	z_i_c;

	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = -2 * c_r * c_i + c_i;
	z_r = z_r_c - z_i_c + c_r;
	while (z_r_c + z_i_c <= 4 && max_iter)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = -2 * z_r * z_i + c_i;
		z_r = z_r_c - z_i_c + c_r;
		max_iter--;
	}
	return (max_iter);
}

__kernel void	luncher(__global t_fractol *fractol, __global int *r)
{
	int	width;
	int	height;
	int	x;
	int	y;
	double	c_r;
	double	c_i;

	width = get_global_size(0);
	height = get_global_size(1);
	x = get_global_id(0);
	y = get_global_id(1);

	c_r = (-(width / 2) + x) / fractol->zoom + fractol->x;
	c_i = (-(height / 2) + y) / fractol->zoom + fractol->y;

	r[x + (y * width)] = color(
		((float)(fractol->max_iter - mandelbrot(c_r, c_i, fractol->max_iter))
		/ fractol->max_iter), fractol->color_indice);
}
