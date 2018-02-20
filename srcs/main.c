/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/20 08:12:24 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <libft.h>
#include <fractol.h>
#include <opencl.h>

int			main(int argc, char **argv)
{
	argc--;
	argv++;
//	if (argc != 1)
//		show_usage();


	t_mlxyz		*mlxyz;
	mlxyz = mlxyz_init();


	t_fractol	fractol;
	fractol.render = 1;
	fractol.max_iter = 100;
	fractol.zoom = 100;
	fractol.x = 0;
	fractol.y = 0;


	t_opencl	*opencl;
	opencl = (t_opencl*)malloc(sizeof(t_opencl));
	if (!opencl)
		return (0);
	ft_bzero(opencl, sizeof(t_opencl));

	init_opencl(opencl);
	set_kernel(opencl, mlxyz);

	fractol.opencl = opencl;

	mlxyz->app = &fractol;


	mlx_loop(mlxyz->mlx);
//	while (1){};
	return (0);
}
