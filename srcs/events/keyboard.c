/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 15:58:53 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "ctx.h"

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
		crash("Broken malloc");
	ft_bzero(keyboard, sizeof(t_keyboard));
	return (keyboard);
}

void		destroy_keyboard(t_keyboard *keyboard)
{
	free(keyboard);
}
