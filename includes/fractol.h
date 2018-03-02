/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 09:11:43 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/02 21:03:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <opencl.h>

typedef struct	s_fractol
{
	char		*fractal_name;
	int			fractal;
	int			render;
	int			max_iter;
	double		zoom;
	double		x;
	double		y;
	double		color_indice;
	double		cre;
	double		cim;
	t_opencl	*opencl;
}				t_fractol;

void			crash_fractol(char *str);
void			close_fractol(t_mlxyz *mlxyz);
void			show_usage(void);
void			set_fractal_type(char *fractal_name, t_fractol *fractol);
void			fractol(t_mlxyz *mlxyz, t_fractol *fractol);
void			fractol_color(t_mlxyz *mlxyz, int x, int y, int i);
void			mandelbrot_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int				mandelbrot(double c_r, double c_i, int iterations);
void			julia_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int				julia(double c_r, double c_i, int iterations, t_mlxyz *mlxyz);
void			burning_ship_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int				burning_ship(double c_r, double c_i, int iterations);
void			tricorn_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int				tricorn(double c_r, double c_i, int iterations);
void			bullet_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int				bullet(double c_r, double c_i, int iterations,
					t_fractol *fractol);
void			buddhabrot_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int				buddhabrot(double c_r, double c_i, int iterations);
#endif
