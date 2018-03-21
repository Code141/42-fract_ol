/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:23:15 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:55:49 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H
# include <stdlib.h>
# include <math.h>

typedef	struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}				t_vector3;

t_vector3		*new_vector3(float x, float y, float z);
void			vector3_set(t_vector3 *v, float x, float y, float z);
void			vect3_normalise(t_vector3 *v);

#endif
