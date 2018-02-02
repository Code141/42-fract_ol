/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:24:41 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:56:19 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/vector4.h>
#include <ctx.h>

t_vector4	*new_vector4(float x, float y, float z, float w)
{
	t_vector4	*v;

	v = (t_vector4*)malloc(sizeof(t_vector4));
	if (!v)
		crash("Broken malloc");
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
	return (v);
}

void		vector4_clear(t_vector4 *v)
{
	v->x = 0;
	v->y = 0;
	v->z = 0;
	v->w = 0;
}

void		vector4_multiply(t_vector4 *v, float factor)
{
	v->x *= factor;
	v->y *= factor;
	v->z *= factor;
}

void		vector4_normalise(t_vector4 *v)
{
	float	size;

	size = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x / size;
	v->y = v->z / size;
	v->z = v->z / size;
}
