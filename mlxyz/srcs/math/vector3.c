/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:22:34 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/vector3.h>
#include <core/core.h>

t_vector3	*new_vector3(float x, float y, float z)
{
	t_vector3	*v;

	v = (t_vector3*)malloc(sizeof(t_vector3));
	if (!v)
		mlxyz_crash("Broken malloc");
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

void		vector3_set(t_vector3 *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void		vect3_normalise(t_vector3 *v)
{
	float	size;

	size = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x / size;
	v->y = v->z / size;
	v->z = v->z / size;
}
