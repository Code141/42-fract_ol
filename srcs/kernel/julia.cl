/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.cl                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:59:33 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/03 18:00:03 by gelambin         ###   ########.fr       */
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
	z_i = (pixel->c_i + pixel->c_i) * pixel->c_r  + fractol->ci;
	z_r = z_r_c - z_i_c + fractol->cr;
	while (z_r_c + z_i_c <= 4 && pixel->iterations < fractol->max_iter)
	{
		z_r_c = z_r * z_r - ((double)(pixel->iterations %3));
		z_i_c = z_i * z_i;
		z_i = (z_i + z_i) * z_r  + fractol->ci;
		z_r = z_r_c - z_i_c + fractol->cr;
		pixel->value += (z_r_c + z_i_c);
		pixel->iterations++;
	}
}
