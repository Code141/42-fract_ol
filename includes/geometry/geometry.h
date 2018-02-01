/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/19 16:27:32 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <stdlib.h>
# include "vector.h"

typedef	struct	s_edge
{
	t_vector4	*vertices[2];
}				t_edge;

typedef	struct	s_face
{
	t_edge		*edges[3];
}				t_face;

typedef struct	s_geometry
{
	t_vector4	**vertices;
	t_edge		**edges;
	t_face		**faces;
}				t_geometry;

t_edge			*new_edge(t_vector4 *v1, t_vector4 *v2);
t_face			*new_face(t_edge *edge1, t_edge *edge2, t_edge *edge3);
void			destroy_geometry(t_geometry *geo);

#endif
