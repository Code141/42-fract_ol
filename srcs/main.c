/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/07 09:13:08 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlxyz.h>
#include <fractol.h>

typedef struct	s_mandelbrot
{
/*
	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;
*/
}				t_mandelbrot;


int			main(int argc, char **argv)
{
	t_mlxyz		*mlxyz;
	t_fractol	*fractol;
	
	argc--;
	argv++;
//	if (argc != 1)
//		show_usage();
	mlxyz = mlxyz_init();
	
	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		crash("t_fractol malloc fail");
	fractol->zoom = 100;
	mlxyz->app = fractol;

	mlx_loop(mlxyz->mlx);
	return (0);
}
