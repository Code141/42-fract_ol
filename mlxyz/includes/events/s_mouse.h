/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mouse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:02:10 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:48:22 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MOUSE_H
# define S_MOUSE_H

typedef struct	s_mouse
{
	int		button[10];
	int		x;
	int		y;
	int		last_x;
	int		last_y;
}				t_mouse;

#endif
