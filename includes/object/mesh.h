/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:57:04 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/22 19:15:39 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H
# include <stdlib.h>
# include "vector.h"
# include "matrice4.h"
# include "geometry.h"
# include "material.h"

typedef struct	s_mesh
{
	t_geometry	*geometry;
	t_material	*material;
	t_vector4	pos;
	t_vector4	rot;
	t_vector4	scale;
	t_matrice4	matrice;
}				t_mesh;

t_mesh			*new_mesh(t_geometry *geometry, t_material *material);
void			destroy_mesh(t_mesh *mesh);

#endif
