/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:52:57 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/11 08:19:02 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlxyz.h>

int		close_fractol(t_mlxyz *mlxyz)
{
	mlxyz_close(mlxyz);
	while (1);
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

void	show_usage(void)
{
	ft_putstr("usage: fractol");
	ft_putstr(" target_file\n");
	exit(0);
}
