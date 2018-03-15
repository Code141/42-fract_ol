/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:55:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 21:16:39 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color/s_color_rgba.h>

t_color_rgba	color_set_rgba(char r, char g, char b, char a)
{
	t_color_rgba	color;

	color.c.r = r;
	color.c.g = g;
	color.c.b = b;
	color.c.a = a;
	return (color);
}

t_color_rgba	color_blend(t_color_rgba *ca, t_color_rgba *cb, float ratio)
{
	t_color_rgba c3;

	c3.c.r = (unsigned char)((cb->c.r - ca->c.r) * ratio + ca->c.r);
	c3.c.g = (unsigned char)((cb->c.g - ca->c.g) * ratio + ca->c.g);
	c3.c.b = (unsigned char)((cb->c.b - ca->c.b) * ratio + ca->c.b);
	c3.c.a = (unsigned char)0;
	return (c3);
}

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
