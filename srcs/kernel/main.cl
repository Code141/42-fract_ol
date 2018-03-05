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

typedef union		u_color_rgba
{
	unsigned int	hex;
	struct			s_c
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}				c;
}					t_color_rgba;

unsigned char	color_canal_sub(unsigned char base, unsigned char value)
{
	return ((base - value < 0) ? 0 : base - value);
}

unsigned char	color_canal_add(unsigned char base, unsigned char value)
{
	return ((base + value > 255) ? 255 : base + value);
}

unsigned int	color(t_pixel *pixel, double c_indice)
{
	t_color_rgba c;

	c.hex = 0;
	if (pixel->pos == 1)
		return (0xffffff);
	if (pixel->pos == 0)
		return (0xffffff);

	c.c.r = color_canal_add(c.c.r, 255 * ((sin(M_PI_F * ((pixel->pos + M_PI_F * 2 * c_indice)) * 8) + 1) / 2));
	c.c.g = color_canal_add(c.c.g, 255 * ((sin(M_PI_F * pixel->pos * 6) + 1) / 2));
	c.c.b = color_canal_add(c.c.b, 255 * ((sin(M_PI_F * pixel->pos * 3 * c_indice) + 1) / 2));

	c.c.r = color_canal_add(c.c.r, pixel->value * 1.5);
	c.c.g = color_canal_add(c.c.g, pixel->value * 1.5);
	c.c.b = color_canal_add(c.c.b, pixel->value * 1.5);

	c.c.r = color_canal_sub(c.c.r, (pixel->iterations % 2) * 0x66);
	c.c.g = color_canal_sub(c.c.g, (pixel->iterations % 2) * 0x66);
	c.c.b = color_canal_sub(c.c.b, (pixel->iterations % 2) * 0x66);

	return (c.hex);
}

__kernel void	luncher(__global t_fractol *fractol, __global int *r)
{
	t_pixel	pixel;
	int	width;
	int	height;
	int	x;
	int	y;
	int i;

	pixel.width = get_global_size(0);
	pixel.height = get_global_size(1);
	pixel.x = get_global_id(0);
	pixel.y = get_global_id(1);
	pixel.index = pixel.x + (pixel.y * pixel.width);
	pixel.max_iter = fractol->max_iter;
	pixel.c_r = (-(pixel.width / 2) + pixel.x) / fractol->zoom + fractol->x;
	pixel.c_i = (-(pixel.height / 2) + pixel.y) / fractol->zoom + fractol->y;
	pixel.value = 0;
	iterations(fractol, &pixel);
	pixel.pos = ((float)(pixel.iterations) / fractol->max_iter);
	r[pixel.index] = color(&pixel, fractol->color_indice);
}
