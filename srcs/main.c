/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/15 04:03:37 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <libft.h>
#include <fractol.h>
#include <opencl.h>

int			main(int argc, char **argv)
{
	t_mlxyz		*mlxyz;
	t_fractol	fractol;

	argc--;
	argv++;
	//	if (argc != 1)
	//		show_usage();
	mlxyz = mlxyz_init();

	fractol.max_iter = 20;
	fractol.zoom = 150;
	fractol.x = 0;
	fractol.y = 0;
	
	char *str;

	str = NULL;
	str = ft_get_file("file1");
	if (str)
	{
		ft_putstr(str);
		free(str);
	}

//	test();

	init_opencl();

	mlxyz->app = &fractol;
//	mlx_loop(mlxyz->mlx);

//	while (1){};
	return (0);
}
