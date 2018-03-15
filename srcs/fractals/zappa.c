/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:09:52 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 23:13:44 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_STRUCT_H
# include <math.h>
#endif
#include <fractol_struct.h>
#define ABS(value) (((value) < 0) ? -((value)) : (value))

void	zappa(t_pixel *pixel)
{
	double	x;
	double	y;
	double	i;

	i = 0;
	pixel->value = 0;
	pixel->iterations = 0;
	x = cos(pixel->cr * 4);
	y = cos(pixel->ci * 4) + 0.1;
	while (((x + i) < y + i || (y + i) < x)
		&&
		pixel->iterations < pixel->max_iter)
	{
		x += 1.2 * (pixel->cr_custom / 1.5);
		y /= 1.1 / pixel->ci_custom;
		x *= 1.1;
		y *= 1.1;
		pixel->iterations++;
		i = (double)pixel->iterations / 2;
	}
}
