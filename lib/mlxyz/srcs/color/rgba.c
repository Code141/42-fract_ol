/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:55:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:46:26 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color/color.h>

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
