/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/11 02:18:57 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events/keyboard.h>
#include <core/core.h>
#include <events/s_keyboard.h>

int			mlxyz_key_release(int keycode, t_mlxyz *mlxyz)
{
	mlxyz->keyboard->key[keycode] = 0;
	return (1);
}

int			mlxyz_key_press(int keycode, t_mlxyz *mlxyz)
{
	ft_putstr("KeyPress [");
	ft_putnbr(keycode);
	ft_putstr("]\n");
	mlxyz->keyboard->key[keycode] = 1;
	mlxyz->keyboard->key_press(mlxyz, keycode);
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
