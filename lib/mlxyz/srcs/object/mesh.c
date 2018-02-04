/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:38:45 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object/mesh.h>
#include <core/core.h>

t_mesh	*new_mesh(t_geometry *geometry, t_material *material)
{
	t_mesh *mesh;

	mesh = (t_mesh*)malloc(sizeof(t_mesh));
	if (!mesh)
		mlxyz_crash("Broken malloc");
	mesh->geometry = geometry;
	mesh->material = material;
	set_point(0, 0, 0, &mesh->pos);
	set_angle(0, 0, 0, &mesh->rot);
	matrice4_init(&mesh->matrice);
	return (mesh);
}

void	destroy_mesh(t_mesh *mesh)
{
	destroy_geometry(mesh->geometry);
	destroy_material(mesh->material);
	free(mesh);
}
