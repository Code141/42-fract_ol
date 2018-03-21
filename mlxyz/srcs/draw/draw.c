/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:25:27 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/22 14:31:45 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw/draw.h>

int			projection(t_mlxyz *mlxyz, t_vector4 *v1, t_vector2 *v2)
{
	float		normal_z;

	normal_z = v1->z / (mlxyz->camera->far - mlxyz->camera->near);
	v2->x = mlxyz->camera->near * v1->x / normal_z;
	v2->y = mlxyz->camera->near * v1->y / normal_z;
	v2->x += (mlxyz->screen->width / 2);
	v2->y += (mlxyz->screen->height / 2);
	if (v1->z < mlxyz->camera->near / 10 || v1->z > mlxyz->camera->far * 10)
		return (0);
	if (v2->x < 0 || v2->x > mlxyz->screen->width
		|| v2->y < 0 || v2->y > mlxyz->screen->height)
		return (0);
	return (1);
}

t_vector2	iso_projection(t_mlxyz *mlxyz, t_vector4 *v1, t_mesh *mesh)
{
	t_vector2	v2;

	(void)mesh;
	v2.x = v1->x;
	v2.y = v1->y;
	v2.x += (mlxyz->screen->width / 2);
	v2.y += (mlxyz->screen->height / 2);
	return (v2);
}

void		draw_all(t_mlxyz *mlxyz, t_list *elements, t_matrice4 *m1)
{
	t_mesh		*mesh;
	t_object	*object;
	t_matrice4	m2;

	while (elements)
	{
		object = (t_object*)elements->content;
		matrice_product(&object->matrice, m1, &m2);
		mesh = object->mesh;
		if (mesh)
			draw_mesh(mlxyz, object, &m2);
		if (object->children)
			draw_all(mlxyz, object->children, &m2);
		elements = elements->next;
	}
}

void		draw_obj(t_mlxyz *mlxyz, t_object *object)
{
	t_mesh		*mesh;

	mesh = object->mesh;
	if (mesh)
		draw_mesh(mlxyz, object, &object->matrice);
}

void		render(t_mlxyz *mlxyz)
{
	(void)mlxyz;
}
