/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:44:07 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/19 20:19:36 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_loop.h>
#include <mlxyz.h>
#include <fractol.h>

void	cadre(t_mlxyz *mlxyz)
{
	t_vector2	v1;
	t_vector2	v2;

	v1.x = 0;
	v1.y = 0;
	v2.x = 200;
	v2.y = 200;
	square_full(mlxyz->screen->canevas, v1, v2, 0x888888);
}

void	txt_1(t_mlxyz *mlxyz, t_fractol *fractol)
{
	char *str;

	str = ft_itoa(mlxyz->stats->fps[0]);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 0, 0x0, str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 30, 0, 0x0, "Fps");
	free(str);
	str = ft_itoa(mlxyz->stats->ms[0]);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 100, 0, 0x0, str);
	if (mlxyz->stats->ms[0] < 100)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 125, 0, 0x0, "Ms");
	else
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 135, 0, 0x0, "Ms");
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 70, 0x0, "Iterations :");
	str = ft_itoa(fractol->max_iter);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 130, 70, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 90, 0x0, "Render :");
	if (fractol->render % 2)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 90, 90, 0xff00, "GPU");
	else
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win,
			90, 90, 0xff0000, "CPU");
}

void	txt_2(t_mlxyz *mlxyz, t_fractol *fractol)
{
	char *str;

	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 110, 0x0, "Lock :");
	if (!(fractol->lock % 2))
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 110, 0xff00, "On");
	else
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 110,
				0xff0000, "Off");
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 130, 0x0, "Zoom :");
	str = ft_itoa(fractol->zoom);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 130, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 150, 0x0, "Cr :");
	if (fractol->cr_custom < 0)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 50, 150, 0x0, "-");
	str = ft_itoa(fabs(fractol->cr_custom));
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 65, 150, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 75, 150, 0x0, ".");
	str = ft_itoa(fabs(
				(fractol->cr_custom - ((int)fractol->cr_custom))) * 1000000);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 85, 150, 0x0, str);
	free(str);
}

void	txt_3(t_mlxyz *mlxyz, t_fractol *fractol)
{
	char *str;

	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 170, 0x0, "Ci :");
	if (fractol->ci_custom > 0)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 50, 170, 0x0, "-");
	str = ft_itoa(fabs(fractol->ci_custom));
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 65, 170, 0x0, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 75, 170, 0x0, ".");
	str = ft_itoa(fabs(
				(fractol->ci_custom - ((int)fractol->ci_custom))) * 1000000);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 85, 170, 0x0, str);
	free(str);
}

void	hud(t_mlxyz *mlxyz, t_fractol *fractol)
{
	render_aux(mlxyz, *fractol);
	cadre(mlxyz);
	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
		mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	txt_1(mlxyz, fractol);
	txt_2(mlxyz, fractol);
	txt_3(mlxyz, fractol);
}
