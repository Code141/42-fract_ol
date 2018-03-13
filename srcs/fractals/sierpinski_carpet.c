/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:49:31 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/13 23:17:36 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_struct.h>
#define ABS(value) (((value) < 0) ? -((value)) : (value))

void	sierpinski_carpet(t_pixel *pixel)
{
	double	x;
	double	y;
	double i;

	pixel->value = 0;
	pixel->iterations = 0;

	x = ABS(pixel->cr);
	y = ABS(pixel->ci);

	i = 1;

	while ((x < 1.5 * i || y < 1.5 * i) && pixel->iterations < pixel->max_iter)
	{

		if ((int)x % 3 == 1)
			x = 0;
		x *= 3;
		if ((int)y % 3 == 1)
			y = 0;
		y *= 3;

//		pixel->value = x + y;
		pixel->iterations++;
	}
}
