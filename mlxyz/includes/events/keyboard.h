/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:02:11 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:48:15 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# include <stdlib.h>
# include <libft.h>
# include <core/core.h>
# include <events/s_keyboard.h>

int				mlxyz_key_release(int keycode, t_mlxyz *mlxyz);
int				mlxyz_key_press(int keycode, t_mlxyz *mlxyz);
t_keyboard		*new_keyboard(void);
void			destroy_keyboard(t_keyboard *keyboard);

#endif
