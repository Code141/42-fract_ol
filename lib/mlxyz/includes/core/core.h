/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:13 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 16:07:55 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <mlx.h>
# include <screen/screen.h>
# include <hud/hud.h>
# include <hud/stats.h>
# include <events/keyboard.h>
# include <events/mouse.h>
# include <object/scene.h>
# include <object/camera.h>

# define PI 3.14159265
# define RAD PI / 180
# define TO_RAD(x) ((x) * PI / 180.0)
# define TO_DEG(x) ((x) * 180.0 / PI)


typedef	struct	s_mlxyz
{
	void		*mlx;
	t_screen	*screen;
	t_stats		*stats;
	t_hud		*hud;
	t_keyboard	*keyboard;
	t_mouse		*mouse;
	t_scene		*scene;
	t_camera	*camera;
}				t_mlxyz;

t_mlxyz			*mlxyz_init(void);
void			mlxyz_close(t_mlxyz *mlxyz);
void			mlxyz_crash(char *str);

#endif
