/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:49:12 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 14:54:08 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_struct.h>

void	bullet(t_pixel *pixel)
{
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;

	pixel->value = 0;
	pixel->iterations = 0;
	z_r_c = pixel->cr * pixel->cr;
	z_i_c = pixel->ci * pixel->ci;
	z_i = (pixel->ci + pixel->ci) * pixel->cr + pixel->ci;
	z_r = z_r_c - z_i_c + pixel->cr;
	while (z_r_c + z_i_c <= 4 && pixel->iterations < pixel->max_iter)
	{
		z_r_c = z_r * (z_r / pixel->cr_custom) + -(pixel->cr_custom);
		z_i_c = z_i * z_i - z_r;
		z_i = (z_i + z_i) * z_r;
		z_r = z_r_c - z_i_c + pixel->cr;
		pixel->value += (z_r_c + z_i_c) * 2;
		pixel->iterations++;
	}
}
