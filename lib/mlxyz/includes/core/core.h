/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:28:41 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/13 18:56:30 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
# include <mlx.h>
# include <screen/screen.h>
# include <hud/hud.h>
# include <hud/stats.h>
# include <events/s_keyboard.h>
# include <events/s_mouse.h>
# include <object/scene.h>
# include <object/camera.h>
# include <opencl/opencl.h>
# define PI 3.14159265
# define RAD PI / 180
# define TO_RAD(x) ((x) * PI / 180.0)
# define TO_DEG(x) ((x) * 180.0 / PI)


typedef	struct	s_mlxyz		t_mlxyz;
struct	s_mlxyz
{
	void		*mlx;
	t_screen	*screen;
	t_stats		*stats;
	t_hud		*hud;
	t_keyboard	*keyboard;
	t_mouse		*mouse;
	t_scene		*scene;
	t_camera	*camera;
	t_opencl	*opencl;
	void		*app;
	void		(*loop_app)(t_mlxyz* mlxyz);
};

t_mlxyz			*mlxyz_init();
void			mlxyz_close(t_mlxyz *mlxyz);
void			mlxyz_crash(char *str);

#endif
