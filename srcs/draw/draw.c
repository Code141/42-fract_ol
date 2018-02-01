/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:25:27 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 18:57:25 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int			projection(t_ctx *ctx, t_vector4 *v1, t_vector2 *v2)
{
	float		normal_z;

	normal_z = v1->z / (ctx->camera->far - ctx->camera->near);
	v2->x = ctx->camera->near * v1->x / normal_z;
	v2->y = ctx->camera->near * v1->y / normal_z;
	v2->x += (ctx->screen->width / 2);
	v2->y += (ctx->screen->height / 2);
	if (v1->z < ctx->camera->near / 10 || v1->z > ctx->camera->far * 10)
		return (0);
	if (v2->x < 0 || v2->x > ctx->screen->width
		|| v2->y < 0 || v2->y > ctx->screen->height)
		return (0);
	return (1);
}

t_vector2	iso_projection(t_ctx *ctx, t_vector4 *v1, t_mesh *mesh)
{
	t_vector2	v2;

	(void)mesh;
	v2.x = v1->x;
	v2.y = v1->y;
	v2.x += (ctx->screen->width / 2);
	v2.y += (ctx->screen->height / 2);
	return (v2);
}

void		draw_all(t_ctx *ctx, t_list *elements, t_matrice4 *m1)
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
			draw_mesh(ctx, object, &m2);
		if (object->children)
			draw_all(ctx, object->children, &m2);
		elements = elements->next;
	}
}

void		draw_obj(t_ctx *ctx, t_object *object)
{
	t_mesh		*mesh;

	mesh = object->mesh;
	if (mesh)
		draw_mesh(ctx, object, &object->matrice);
}

void		render(t_ctx *ctx)
{

}
