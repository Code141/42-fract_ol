/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice4_rot_trans.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:28:01 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:54:07 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/matrice4.h>

void		matrice_translation(t_matrice4 *m1, t_vector4 *v)
{
	t_matrice4	m2;

	matrice4_init(&m2);
	m2.m[3] = v->x;
	m2.m[7] = v->y;
	m2.m[11] = v->z;
	matrice_product(m1, &m2, m1);
}

void		matrice_translation_from_world(t_matrice4 *m1, t_vector4 *v)
{
	t_matrice4	m2;

	matrice4_init(&m2);
	m2.m[3] = v->x;
	m2.m[7] = v->y;
	m2.m[11] = v->z;
	matrice_product(&m2, m1, m1);
}

void		matrice_rotation_x_from_world(t_matrice4 *m1, float angle)
{
	t_matrice4 m2;

	matrice4_init(&m2);
	m2.m[5] = cos(angle);
	m2.m[6] = -sin(angle);
	m2.m[9] = sin(angle);
	m2.m[10] = cos(angle);
	matrice_product(&m2, m1, m1);
}

void		matrice_rotation_y_from_world(t_matrice4 *m1, float angle)
{
	t_matrice4 m2;

	matrice4_init(&m2);
	m2.m[0] = cos(angle);
	m2.m[2] = -sin(angle);
	m2.m[8] = sin(angle);
	m2.m[10] = cos(angle);
	matrice_product(&m2, m1, m1);
}

void		matrice_rotation_z_from_world(t_matrice4 *m1, float angle)
{
	t_matrice4 m2;

	matrice4_init(&m2);
	m2.m[0] = cos(angle);
	m2.m[1] = -sin(angle);
	m2.m[4] = sin(angle);
	m2.m[5] = cos(angle);
	matrice_product(&m2, m1, m1);
}
