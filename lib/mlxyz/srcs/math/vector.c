/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:44:18 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:59:32 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/vector.h>

t_vector4	*new_point(float x, float y, float z)
{
	return (new_vector4(x, y, z, 1));
}

t_vector4	*new_angle(float x, float y, float z)
{
	return (new_vector4(x, y, z, 0));
}

void		set_point(float x, float y, float z, t_vector4 *v)
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = 1;
}

void		set_angle(float x, float y, float z, t_vector4 *v)
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = 0;
}

void		swap_vect2(t_vector2 *v1, t_vector2 *v2)
{
	t_vector2 vtmp;

	vtmp = *v1;
	*v1 = *v2;
	*v2 = vtmp;
}
