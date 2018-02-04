/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 18:15:41 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlxyz.h>


int			main(int argc, char **argv)
{
	t_mlxyz		*mlxyz;

	argc--;
	argv++;
//	if (argc != 1)
//		show_usage();
	mlxyz = mlxyz_init();
	mlx_loop(mlxyz->mlx);
	return (0);
}
