/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:23:44 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:56:06 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4_H
# define VECTOR4_H
# include <stdlib.h>
# include <math.h>

typedef	struct	s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector4;

t_vector4		*new_vector4(float x, float y, float z, float w);
void			vector4_clear(t_vector4 *v);
void			vector4_multiply(t_vector4 *v, float factor);
void			vector4_normalise(t_vector4 *v);

#endif
