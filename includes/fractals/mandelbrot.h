/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 07:49:32 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/20 12:24:30 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

void	mandelbrot_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int		mandelbrot(double c_r, double c_i, int iterations);

#endif
