/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:44 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 16:21:42 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "vector3.h"
# include "vector4.h"

typedef	struct	s_vector2
{
	int	x;
	int	y;
}				t_vector2;

t_vector4		*new_point(float x, float y, float z);
t_vector4		*new_angle(float x, float y, float z);
void			set_point(float x, float y, float z, t_vector4 *v);
void			set_angle(float x, float y, float z, t_vector4 *v);
void			swap_vect2(t_vector2 *v1, t_vector2 *v2);

#endif
