/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:49:15 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:53:47 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/matrice4.h>

void		matrice4_init(t_matrice4 *m)
{
	m->m[0] = 1;
	m->m[1] = 0;
	m->m[2] = 0;
	m->m[3] = 0;
	m->m[4] = 0;
	m->m[5] = 1;
	m->m[6] = 0;
	m->m[7] = 0;
	m->m[8] = 0;
	m->m[9] = 0;
	m->m[10] = 1;
	m->m[11] = 0;
	m->m[12] = 0;
	m->m[13] = 0;
	m->m[14] = 0;
	m->m[15] = 1;
}

t_vector4	matrice_apply(t_matrice4 *m, t_vector4 *p)
{
	t_vector4	p2;

	p2.x = p->x * m->m[0] + p->y * m->m[1] + p->z * m->m[2] + m->m[3];
	p2.y = p->x * m->m[4] + p->y * m->m[5] + p->z * m->m[6] + m->m[7];
	p2.z = p->x * m->m[8] + p->y * m->m[9] + p->z * m->m[10] + m->m[11];
	p2.w = p->x * m->m[12] + p->y * m->m[13] + p->z * m->m[14] + m->m[15];
	return (p2);
}

void		matrice_product(t_matrice4 *m1, t_matrice4 *m2, t_matrice4 *m3)
{
	int			i;
	t_matrice4	m4;

	i = 0;
	while (i < 16)
	{
		m4.m[i] = (m1->m[(i / 4) * 4 + 0] * m2->m[i % 4 + 0])
				+ (m1->m[(i / 4) * 4 + 1] * m2->m[i % 4 + 4])
				+ (m1->m[(i / 4) * 4 + 2] * m2->m[i % 4 + 8])
				+ (m1->m[(i / 4) * 4 + 3] * m2->m[i % 4 + 12]);
		i++;
	}
	*m3 = m4;
}
