/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:01 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/24 18:50:39 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
# include "color.h"

typedef struct	s_material
{
	t_color_rgba	color;
	t_color_rgba	color_b;
}				t_material;

typedef struct	s_radian
{
	int				nb_step;
	t_color_rgba	colors[];
}				t_radian;

t_material		*new_material(t_color_rgba color);
void			destroy_material(t_material *material);

#endif
