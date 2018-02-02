/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:09 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:51:35 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE4_H
# define MATRICE4_H
# include <stdlib.h>
# include <math.h>
# include <math/vector.h>

typedef struct	s_matrice4
{
	float	m[16];
}				t_matrice4;

void			matrice4_init(t_matrice4 *m);

t_vector4		matrice_apply(t_matrice4 *m, t_vector4 *p);
void			matrice_product(t_matrice4 *m1, t_matrice4 *m2, t_matrice4 *m3);
void			matrice_multiply(t_matrice4 *m1, float factor);

void			matrice_translation(t_matrice4 *m1, t_vector4 *v);
void			matrice_translation_from_world(t_matrice4 *m1, t_vector4 *v);

void			matrice_rotation_x_from_world(t_matrice4 *m, float angle);
void			matrice_rotation_y_from_world(t_matrice4 *m, float angle);
void			matrice_rotation_z_from_world(t_matrice4 *m, float angle);

void			matrice_rotation_x(t_matrice4 *m, float angle);
void			matrice_rotation_y(t_matrice4 *m, float angle);
void			matrice_rotation_z(t_matrice4 *m, float angle);
#endif
