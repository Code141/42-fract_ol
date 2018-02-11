/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/11 09:00:45 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlxyz.h>
#include <fractol.h>
#include <closing.h>

#include <OpenCL/cl.h>
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
		crash_fractol("t_fractol malloc fail");
	fractol->max_iter = 20;
	fractol->zoom = 150;
	fractol->x = 0;
	fractol->y = 0;
	mlxyz->app = fractol;
	mlx_loop(mlxyz->mlx);
	return (0);
}
