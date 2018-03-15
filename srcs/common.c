/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:07:13 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 21:56:54 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# include <fractol.h>
#endif
#define M_PI_F 3.1415926536

void			iterations(int id, t_pixel *pixel)
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
	if (id == 5)
		julia_fun(pixel);
	if (id == 6)
		sierpinski_carpet(pixel);
	if (id == 7)
		zappa(pixel);
}

unsigned int	color(t_pixel *pixel, double cindice)
{
	t_color_rgba	c;

	c.hex = 0;
	if (pixel->pos == 1)
		return (0xffffff);
	if (pixel->pos == 0)
		return (0x000000);
	c.c.r = color_canal_add(c.c.r, 255 *
		(sin(((M_PI_F) * (pixel->pos + M_PI_F * 2 * cindice)) * 8) + 1) / 2);
	c.c.g = color_canal_add(c.c.g, 255 *
		(sin(M_PI_F * pixel->pos * 6) + 1) / 2);
	c.c.b = color_canal_add(c.c.b, 255 *
		(sin(M_PI_F * pixel->pos * 3 * cindice) + 1) / 2);
	c.c.r = color_canal_add(c.c.r, pixel->value * 1.5);
	c.c.g = color_canal_add(c.c.g, pixel->value * 1.5);
	c.c.b = color_canal_add(c.c.b, pixel->value * 1.5);
	c.c.r = color_canal_sub(c.c.r, (pixel->iterations % 2) * 0x66);
	c.c.g = color_canal_sub(c.c.g, (pixel->iterations % 2) * 0x66);
	c.c.b = color_canal_sub(c.c.b, (pixel->iterations % 2) * 0x66);
	return (c.hex);
}

unsigned int	color_1(t_pixel *pixel, double cindice)
{
	t_color_rgba	c;

	c.hex = 0;
	if (pixel->pos == 1)
		return (0xffffff);
	if (pixel->pos == 0)
		return (0x000000);
	c.c.r = color_canal_add(c.c.r, 255 *
		(sin(((M_PI_F) * (pixel->pos + M_PI_F * 2 * cindice)) * 8) + 1) / 2);
	c.c.g = color_canal_add(c.c.g, 255 *
		(sin(M_PI_F * pixel->pos * 6) + 1) / 2);
	c.c.b = color_canal_add(c.c.b, 255 *
		(sin(M_PI_F * pixel->pos * 3 * cindice) + 1) / 2);
	c.c.r = color_canal_add(c.c.r, pixel->value * 1.5);
	c.c.g = color_canal_add(c.c.g, pixel->value * 1.5);
	c.c.b = color_canal_add(c.c.b, pixel->value * 1.5);
	c.c.r = color_canal_sub(c.c.r, (pixel->iterations % 2) * 0x66);
	c.c.g = color_canal_sub(c.c.g, (pixel->iterations % 2) * 0x66);
	c.c.b = color_canal_sub(c.c.b, (pixel->iterations % 2) * 0x66);
	return (c.hex);
}
