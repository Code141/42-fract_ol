/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.cl                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2018/03/03 17:59:33 by gelambin          #+#    #+#             */
/*   updated: 2018/03/03 18:00:03 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	iterations(__global t_fractol *fractol, t_pixel *pixel)
{
	double	z_r;
	double	z_i;
	double	z_r_c;
	double	z_i_c;

	pixel->iterations = 0;

	z_r_c = pixel->c_r * pixel->c_r;
	z_i_c = pixel->c_i * pixel->c_i;
	z_i = (pixel->c_i + pixel->c_i) * pixel->c_r + pixel->c_i;
	z_r = z_r_c - z_i_c + pixel->c_r;

	while (z_r_c + z_i_c <= 4 && pixel->iterations < fractol->max_iter)
	{
		z_r_c = z_r * (z_r / fractol->cr) + -fractol->cr;
		z_i_c = z_i * z_i - z_r;
		z_i = (z_i + z_i) * z_r;
		z_r = z_r_c - z_i_c + pixel->c_r;
		pixel->value += (z_r_c + z_i_c);
		pixel->iterations++;
	}
}
