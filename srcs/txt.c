/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:44:07 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/13 20:16:17 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlxyz.h>

void	txt_1(t_mlxyz *mlxyz, t_fractol *fractol)
{
	char *str;

	str = ft_itoa(mlxyz->stats->fps[0]);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 0, 0x0, str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 30, 0, 0x0, "Fps");
	free(str);
	str = ft_itoa(mlxyz->stats->ms[0]);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 100, 0, 0x0, str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 125, 0, 0x0, "Ms");
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 280, 0x0, "Iterations :");
	str = ft_itoa(fractol->max_iter);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 130, 280, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 300, 0x0, "Render :");
	if (fractol->render % 2)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 90, 300, 0xff00, "GPU");
	else
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win,
			90, 300, 0xff0000, "CPU");
}

void	txt_2(t_mlxyz *mlxyz, t_fractol *fractol)
{
	char *str;

	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 320, 0x0, "Lock :");
	if (fractol->lock % 2)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 320, 0xff0000, "On");
	else
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 320, 0xff00, "Off");
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 340, 0x0, "Zoom :");
	str = ft_itoa(fractol->zoom);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 340, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 360, 0x0, "Cr :");
	if (fractol->cr_custom < 0)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 50, 360, 0x0, "-");
	str = ft_itoa(fabs(fractol->cr_custom));
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 65, 360, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 75, 360, 0x0, ".");
	str = ft_itoa(fabs(
				(fractol->cr_custom - ((int)fractol->cr_custom))) * 1000000);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 85, 360, 0x0, str);
	free(str);
}

void	txt_3(t_mlxyz *mlxyz, t_fractol *fractol)
{
	char *str;

	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 380, 0x0, "Ci :");
	if (fractol->ci_custom > 0)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 50, 380, 0x0, "-");
	str = ft_itoa(fabs(fractol->ci_custom));
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 65, 380, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 75, 380, 0x0, ".");
	str = ft_itoa(fabs(
				(fractol->ci_custom - ((int)fractol->ci_custom))) * 1000000);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 85, 380, 0x0, str);
	free(str);
}
