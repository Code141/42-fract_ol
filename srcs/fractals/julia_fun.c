/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:48:18 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/19 18:56:03 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_struct.h>
#define ABS(value) (((value) < 0) ? -((value)) : (value))

void	julia_fun(t_pixel *pixel)
{
	double	z_r;
	double	z_i;
	double	z_r_c;
	double	z_i_c;

	pixel->value = 0;
	pixel->iterations = 0;
	z_r_c = pixel->cr * pixel->cr;
	z_i_c = pixel->ci * pixel->ci;
	z_i = (pixel->ci + pixel->ci) * pixel->cr + pixel->ci_custom;
	z_r = z_r_c - z_i_c + pixel->cr_custom;
	while (z_r_c + z_i_c <= 4 && pixel->iterations < pixel->max_iter)
	{
		z_r_c = z_r * z_r - ((double)(pixel->iterations % 3));
		z_i_c = z_i * z_i;
		z_i = (z_i + z_i) * z_r + pixel->ci_custom;
		z_r = ABS(z_r_c - z_i_c + pixel->cr_custom);
		pixel->value += (z_r_c + z_i_c) * 3;
		pixel->iterations++;
	}
}
