/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 09:11:43 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/13 21:51:35 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlxyz.h>
# include <fractol_struct.h>

void	crash_fractol(char *str);
void	close_fractol(t_mlxyz *mlxyz);
void	show_usage(void);
void	set_fractal_type(char *fractal_name, t_fractol *fractol);
void	fractol(t_mlxyz *mlxyz, t_fractol *fractol);

void	julia(t_pixel *pixel);
void	mandelbrot(t_pixel *pixel);
void	bullet(t_pixel *pixel);
void	burning_ship(t_pixel *pixel);
void	tricorn(t_pixel *pixel);
void	julia_fun(t_pixel *pixel);
void	sierpinski_carpet(t_pixel *pixel);

void	loop(t_mlxyz *mlxyz);

#endif
