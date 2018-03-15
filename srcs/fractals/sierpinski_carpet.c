/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:49:31 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 15:10:02 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_struct.h>
#define ABS(value) (((value) < 0) ? -((value)) : (value))

void	sierpinski_carpet(t_pixel *pixel)
{
	double	x;
	double	y;
	double	i;
	double	x_c;

	pixel->value = 0;
	pixel->iterations = 0;

	i = 1;
	x = ABS(pixel->cr) + 1.5;
	y = ABS(pixel->ci) + 1.5;
	x_c = ABS(pixel->cr_custom);
	if (x > 3 + 3 * x_c || y > 3 + 3 * x_c)
		return ;
	pixel->iterations++;
	while ((((int)x % 3 != 1) || ((int)y % 3 != 1))
		&& pixel->iterations < pixel->max_iter)
	{
		x *= 3 + 3 * -x_c / 10;
		y *= 3 + 3 * -x_c / 10;
		pixel->iterations++;
	}
}
