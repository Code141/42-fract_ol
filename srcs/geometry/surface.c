/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:42:18 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 12:14:28 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "surface.h"
#include "ctx.h"

static t_vector4	**surface_vertices(int x, int y, int subx, int suby)
{
	t_vector4	**vertices;
	int			i;
	int			j;

	vertices = (t_vector4**)malloc(
		sizeof(t_vector4*) * ((subx + 1) * (suby + 1) + 1));
	if (!vertices)
		crash("Broken malloc");
	i = 0;
	while (i < suby + 1)
	{
		j = 0;
		while (j < subx + 1)
		{
			vertices[(i * (subx + 1)) + j] = new_point(
				x / subx * j - x / 2,
				y / suby * i - y / 2,
				0);
			j++;
		}
		i++;
	}
	vertices[(subx + 1) * (suby + 1)] = NULL;
	return (vertices);
}

static t_edge		**surface_edges(t_vector4 **v, int x, int y)
{
	t_edge	**e;
	int		i;
	int		j;

	if (!(e = (t_edge**)malloc(sizeof(t_edge*) * ((x * y * 3) + (x + y) + 1))))
		crash("Broken malloc");
	i = -1;
	while (i++ < y + 1)
	{
		j = -1;
		while (j++ < x + 1)
		{
			if (j < x)
				e[i * x + j] =
					new_edge(v[i * (x + 1) + j], v[i * (x + 1) + j + 1]);
			if (i < y)
				e[((y + 1) * x) + (i * (x + 1)) + j] =
					new_edge(v[i * (x + 1) + j], v[(i + 1) * (x + 1) + j]);
			if (i < y && j < x)
				e[((y + 1) * x) + (y * (x + 1)) + (i * x + j)] =
					new_edge(v[i * (x + 1) + j], v[(i + 1) * (x + 1) + j + 1]);
		}
	}
	e[(x * y * 3) + (x + y)] = NULL;
	return (e);
}

static t_face		**surface_faces(t_edge **edges, int subx, int suby)
{
	t_face **faces;

	(void)edges;
	(void)subx;
	(void)suby;
	faces = (t_face**)malloc(sizeof(t_face*) * 3);
	if (!faces)
		crash("Broken malloc");
	faces[0] = NULL;
	return (faces);
}

t_geometry			*new_surface(int x, int y, int subx, int suby)
{
	t_geometry	*geo;

	geo = (t_geometry*)malloc(sizeof(t_geometry));
	if (!geo)
		crash("Broken malloc");
	geo->vertices = surface_vertices(x, y, subx, suby);
	geo->edges = surface_edges(geo->vertices, subx, suby);
	geo->faces = surface_faces(geo->edges, subx, suby);
	return (geo);
}
