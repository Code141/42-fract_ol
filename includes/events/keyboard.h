/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:02:11 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 18:31:42 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# include <stdlib.h>
# include "libft.h"

typedef struct	s_keyboard
{
	char	key[300];
}				t_keyboard;

int				key_release(int keycode, t_keyboard *keyboard);
int				key_press(int keycode, t_keyboard *keyboard);
t_keyboard		*new_keyboard(void);
void			destroy_keyboard(t_keyboard *keyboard);

#endif
