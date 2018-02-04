/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:40:07 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <geometry/plane.h>
#include <core/core.h>

static t_vector4	**plane_vertices(int x, int y)
{
	t_vector4 **vertices;

	vertices = (t_vector4**)malloc(sizeof(t_vector4*) * 5);
	if (!vertices)
		mlxyz_crash("Broken malloc");
	vertices[0] = new_point(-x / 2, -y / 2, 0);
	vertices[1] = new_point(-x / 2, y / 2, 0);
	vertices[2] = new_point(x / 2, -y / 2, 0);
	vertices[3] = new_point(x / 2, y / 2, 0);
	vertices[4] = NULL;
	return (vertices);
}

static t_edge		**plane_edges(t_vector4 **vertices)
{
	t_edge **edges;

	edges = (t_edge**)malloc(sizeof(t_edge*) * 6);
	if (!edges)
		mlxyz_crash("Broken malloc");
	edges[0] = new_edge(vertices[0], vertices[1]);
	edges[1] = new_edge(vertices[0], vertices[2]);
	edges[2] = new_edge(vertices[1], vertices[3]);
	edges[3] = new_edge(vertices[2], vertices[3]);
	edges[4] = new_edge(vertices[1], vertices[2]);
	edges[5] = NULL;
	return (edges);
}

static t_face		**plane_faces(t_edge **edges)
{
	t_face **faces;

	faces = (t_face**)malloc(sizeof(t_face*) * 3);
	if (!faces)
		mlxyz_crash("Broken malloc");
	faces[0] = new_face(edges[0], edges[1], edges[4]);
	faces[1] = new_face(edges[2], edges[3], edges[4]);
	faces[2] = NULL;
	return (faces);
}

t_geometry			*new_plane(int x, int y)
{
	t_geometry	*geo;

	geo = (t_geometry*)malloc(sizeof(t_geometry));
	if (!geo)
		mlxyz_crash("Broken malloc");
	geo->vertices = plane_vertices(x, y);
	geo->edges = plane_edges(geo->vertices);
	geo->faces = plane_faces(geo->edges);
	return (geo);
}
