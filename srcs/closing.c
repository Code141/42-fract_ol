/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:52:57 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/22 12:44:28 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlxyz.h>

int		close_fractol(t_mlxyz *mlxyz)
{
	mlxyz_close(mlxyz);
	ft_putstr("Exit.");
	exit(0);
}

void	crash_fractol(char *str)
{
	ft_putendl("========== CRASH ==========");
	ft_putendl(str);
	ft_putendl("===========================");
	exit(1);
}
