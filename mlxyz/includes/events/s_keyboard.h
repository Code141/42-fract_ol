/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_keyboard.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:02:11 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:48:15 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_KEYBOARD_H
# define S_KEYBOARD_H

typedef struct	s_keyboard
{
	void	(*key_press)(void* mlxyz, int keycode);
	char	key[300];
}				t_keyboard;

#endif
