/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 08:14:30 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 16:05:43 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_struct.h>

void	tricorn(t_pixel *pixel)
{
	pixel->value = 0;
	pixel->iterations = 0;
/*
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;

	z_r = 0;
	z_i = 0;
	z_r_c = z_r * z_r;
	z_i_c = z_i * z_i;
	z_i = -2 * z_r * z_i + pixel->ci;
	z_r = z_r_c - z_i_c + pixel->cr;
	while (z_r_c + z_i_c <= 4 && iterations)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = -2 * z_r * z_i + pixel->ci;
		z_r = z_r_c - z_i_c + pixel->cr;
		iterations--;
	}
	return (iterations);
*/
}


