/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:42:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/11 09:24:29 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	
	Mandelbrot
		x1 = -2.1;
		x2 = 0.6;
		y1 = -1.2;
		y2 = 1.2;
*/

int		mandelbrot(double c_r, double c_i, int iterations)
{
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;

	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = (c_i + c_i) * c_r + c_i;
	z_r = z_r_c - z_i_c + c_r;
	while (z_r_c + z_i_c <= 4 && iterations)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = (z_i + z_i) * z_r + c_i;
		z_r = z_r_c - z_i_c + c_r;
		iterations--;
	}
	return (iterations);
}
