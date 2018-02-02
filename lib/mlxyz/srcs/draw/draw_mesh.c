/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:53:31 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:47:53 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw/draw_mesh.h>

void	draw_vertices(t_ctx *ctx, t_mesh *mesh, t_matrice4 *m)
{
	int			i;
	t_vector4	v1;
	t_vector2	v2;

	i = 0;
	while (mesh->geometry->vertices[i])
	{
		v1 = matrice_apply(m, mesh->geometry->vertices[i]);
		if (projection(ctx, &v1, &v2))
			draw_point(
				ctx->screen->canevas,
				v2,
				1,
				color_blend(&mesh->material->color,
					&ctx->camera->fog_color, v1.z
					/ (ctx->camera->far - ctx->camera->near)
					/ 11.5));
		i++;
	}
}

void	draw_edges(t_ctx *ctx, t_mesh *mesh, t_matrice4 *m)
{
	int				i;
	t_vector4		v1a;
	t_vector4		v1b;
	t_vector2		v2a;
	t_vector2		v2b;

	i = 0;
	while (mesh->geometry->edges[i])
	{
		v1a = matrice_apply(m, mesh->geometry->edges[i]->vertices[0]);
		v1b = matrice_apply(m, mesh->geometry->edges[i]->vertices[1]);
		if ((projection(ctx, &v1a, &v2a) + projection(ctx, &v1b, &v2b)))
		{
			line(ctx->screen->canevas, v2a, v2b,
				color_blend(&mesh->material->color, &ctx->camera->fog_color,
				fmin(v1a.z, v1b.z) / (ctx->camera->far - ctx->camera->near)
				/ 11.5));
		}
		i++;
	}
}

void	draw_mesh(t_ctx *ctx, t_object *object, t_matrice4 *m)
{
	t_matrice4		m3;

	matrice_product(m, &object->mesh->matrice, &m3);
	draw_edges(ctx, object->mesh, &m3);
}
