/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:02:10 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:48:22 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H
# include <stdlib.h>
# include <libft.h>
# include <core/core.h>
# include <events/s_mouse.h>

int				button_release(int button, int x, int y, t_mlxyz *mlxyz);
int				button_press(int button, int x, int y, t_mlxyz *mlxyz);
int				mouse_move(int x, int y, t_mlxyz *mlxyz);
t_mouse			*new_mouse(void);
void			destroy_mouse(t_mouse *mouse);

#endif
