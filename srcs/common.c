/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:33:50 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 15:36:00 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FRACTOL_STRUCT_H

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

#endif

#ifndef FRACTOL_STRUCT_H
# include <common.h>
# include <fractol.h>
#endif

unsigned char	color_canal_sub(unsigned char base, unsigned char value)
{
	return ((base - value < 0) ? 0 : base - value);
}

unsigned char	color_canal_add(unsigned char base, unsigned char value)
{
	return ((base + value > 255) ? 255 : base + value);
}

t_color_rgba	color_sub(t_color_rgba base, t_color_rgba value)
{
	t_color_rgba c;

	c.c.r = (base.c.r - value.c.r < 0) ? 0 : base.c.r - value.c.r;
	c.c.g = (base.c.g - value.c.g < 0) ? 0 : base.c.g - value.c.g;
	c.c.b = (base.c.b - value.c.b < 0) ? 0 : base.c.b - value.c.b;
	return (c);
}

t_color_rgba	color_add(t_color_rgba base, t_color_rgba value)
{
	t_color_rgba c;

	c.c.r = (base.c.r + value.c.r > 255) ? 255 : base.c.r + value.c.r;
	c.c.g = (base.c.g + value.c.g > 255) ? 255 : base.c.g + value.c.g;
	c.c.b = (base.c.b + value.c.b > 255) ? 255 : base.c.b + value.c.b;
	return (c);
}

unsigned int	color(t_pixel *pixel, double cindice)
{
	t_color_rgba c;

	c.hex = 0;
	if (pixel->pos == 1)
		return (0xffffff);
	if (pixel->pos == 0)
		return (0xffffff);

	c.c.r = color_canal_add(c.c.r, 255 * ((sin(M_PI_F * ((pixel->pos + M_PI_F * 2 * cindice)) * 8) + 1) / 2));
	c.c.g = color_canal_add(c.c.g, 255 * ((sin(M_PI_F * pixel->pos * 6) + 1) / 2));
	c.c.b = color_canal_add(c.c.b, 255 * ((sin(M_PI_F * pixel->pos * 3 * cindice) + 1) / 2));

	c.c.r = color_canal_add(c.c.r, pixel->value * 1.5);
	c.c.g = color_canal_add(c.c.g, pixel->value * 1.5);
	c.c.b = color_canal_add(c.c.b, pixel->value * 1.5);

	c.c.r = color_canal_sub(c.c.r, (pixel->iterations % 2) * 0x66);
	c.c.g = color_canal_sub(c.c.g, (pixel->iterations % 2) * 0x66);
	c.c.b = color_canal_sub(c.c.b, (pixel->iterations % 2) * 0x66);

	return (c.hex);
}

void	iterations(int id, t_pixel *pixel)
{
	if (id == 0)
		julia(pixel);
	if (id == 1)
		mandelbrot(pixel);
	if (id == 2)
		burning_ship(pixel);
	if (id == 3)
		tricorn(pixel);
	if (id == 4)
		bullet(pixel);
}

