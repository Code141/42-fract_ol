/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:42:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/07 08:57:42 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	mandelbrot(int x, int y)
{
	double i;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;
	double old_z_r;

	c_r = x / zoom_x + x1;
	c_i = y / zoom_y + y1;
	z_r = 0;
	z_i = 0;
	z_r_c = 0; 
	z_i_c = 0;
	i = 0;
	while (z_r_c + z_i_c < 4 && i < iterations)
	{
		old_z_r = z_r;

		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;

		z_r = z_r_c - z_i_c + c_r;
		z_i = 2 * z_i * old_z_r + c_i;

		i++;
	}
	if (i == iterations)
		return (0);
	return (1);
}
*/
