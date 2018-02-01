/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:39:13 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 11:39:25 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "geometry.h"

t_edge		*new_edge(t_vector4 *v1, t_vector4 *v2)
{
	t_edge	*edge;

	edge = (t_edge*)malloc(sizeof(t_edge));
	if (!edge)
		crash("Broken malloc");
	edge->vertices[0] = v1;
	edge->vertices[1] = v2;
	return (edge);
}

t_face		*new_face(t_edge *edge1, t_edge *edge2, t_edge *edge3)
{
	t_face	*face;

	face = (t_face*)malloc(sizeof(t_face));
	if (!face)
		crash("Broken malloc");
	face->edges[0] = edge1;
	face->edges[1] = edge2;
	face->edges[2] = edge3;
	return (face);
}

void		destroy_geometry(t_geometry *geo)
{
	int i;

	i = 0;
	while (geo->vertices[i])
		free(geo->vertices[i++]);
	free(geo->vertices);
	geo->vertices = NULL;
	i = 0;
	while (geo->edges[i])
		free(geo->edges[i++]);
	free(geo->edges);
	geo->edges = NULL;
	i = 0;
	while (geo->faces[i])
		free(geo->faces[i++]);
	free(geo->faces);
	geo->faces = NULL;
}
