/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:41 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/19 19:01:32 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# include <mlx.h>

typedef	struct	s_img
{
	int		width;
	int		height;
	void	*id;
	char	*data;
}				t_img;

typedef	struct	s_screen
{
	void	*win;
	int		width;
	int		height;
	float	ar;
	t_img	*canevas;
}				t_screen;

t_img			*new_canevas(void *mlx, int width, int height);
t_screen		*new_screen(void *mlx, int width, int height, char *name);

#endif
