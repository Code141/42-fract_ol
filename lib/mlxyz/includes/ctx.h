/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:13 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:01:15 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include <mlx.h>
# include <screen/screen.h>
# include <hud/hud.h>
# include <hud/stats.h>
# include <events/keyboard.h>
# include <events/mouse.h>
# include <object/scene.h>
# include <object/camera.h>

typedef	struct	s_ctx
{
	void		*mlx;
	t_screen	*screen;
	t_stats		*stats;
	t_hud		*hud;
	t_keyboard	*keyboard;
	t_mouse		*mouse;
	t_scene		*scene;
	t_camera	*camera;
}				t_ctx;

int				close_fdf(t_ctx *ctx);
void			show_usage(void);
void			crash(char *str);

#endif
