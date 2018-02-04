/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events/keyboard.h>
#include <core/core.h>

int			key_release(int keycode, t_keyboard *keyboard)
{
	keyboard->key[keycode] = 0;
	return (1);
}

int			key_press(int keycode, t_keyboard *keyboard)
{
	keyboard->key[keycode] = 1;
	return (1);
}

t_keyboard	*new_keyboard(void)
{
	t_keyboard	*keyboard;

	keyboard = (t_keyboard*)malloc(sizeof(t_keyboard));
	if (!keyboard)
		mlxyz_crash("Broken malloc");
	ft_bzero(keyboard, sizeof(t_keyboard));
	return (keyboard);
}

void		destroy_keyboard(t_keyboard *keyboard)
{
	free(keyboard);
}
