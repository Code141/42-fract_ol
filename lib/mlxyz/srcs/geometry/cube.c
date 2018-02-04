/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:38:07 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <geometry/cube.h>
#include <core/core.h>

static t_vector4	**cube_vertices(int x, int y, int z)
{
	t_vector4	**vertices;

	vertices = (t_vector4**)malloc(sizeof(t_vector4*) * 9);
	if (!vertices)
		mlxyz_crash("Broken malloc");
	vertices[0] = new_point(-x / 2, -y / 2, z / 2);
	vertices[1] = new_point(-x / 2, y / 2, z / 2);
	vertices[2] = new_point(x / 2, -y / 2, z / 2);
	vertices[3] = new_point(x / 2, y / 2, z / 2);
	vertices[4] = new_point(-x / 2, -y / 2, -z / 2);
	vertices[5] = new_point(-x / 2, y / 2, -z / 2);
	vertices[6] = new_point(x / 2, -y / 2, -z / 2);
	vertices[7] = new_point(x / 2, y / 2, -z / 2);
	vertices[8] = NULL;
	return (vertices);
}

static t_edge		**cube_edges(t_vector4 **vertices)
{
	t_edge	**edges;

	edges = (t_edge**)malloc(sizeof(t_edge*) * 19);
	if (!edges)
		mlxyz_crash("Broken malloc");
	edges[0] = new_edge(vertices[0], vertices[1]);
	edges[1] = new_edge(vertices[0], vertices[2]);
	edges[2] = new_edge(vertices[1], vertices[3]);
	edges[3] = new_edge(vertices[2], vertices[3]);
	edges[4] = new_edge(vertices[1], vertices[2]);
	edges[5] = new_edge(vertices[4], vertices[5]);
	edges[6] = new_edge(vertices[4], vertices[6]);
	edges[7] = new_edge(vertices[5], vertices[7]);
	edges[8] = new_edge(vertices[6], vertices[7]);
	edges[9] = new_edge(vertices[5], vertices[6]);
	edges[10] = new_edge(vertices[0], vertices[4]);
	edges[11] = new_edge(vertices[1], vertices[4]);
	edges[12] = new_edge(vertices[1], vertices[5]);
	edges[13] = new_edge(vertices[3], vertices[5]);
	edges[14] = new_edge(vertices[3], vertices[7]);
	edges[15] = new_edge(vertices[3], vertices[6]);
	edges[16] = new_edge(vertices[2], vertices[6]);
	edges[17] = new_edge(vertices[2], vertices[4]);
	edges[18] = NULL;
	return (edges);
}

static t_face		**cube_faces(t_edge **edges)
{
	t_face	**faces;

	(void)edges;
	faces = (t_face**)malloc(sizeof(t_face*) * 3);
	if (!faces)
		mlxyz_crash("Broken malloc");
	faces[0] = NULL;
	return (faces);
}

t_geometry			*new_cube(int x, int y, int z)
{
	t_geometry	*geo;

	geo = (t_geometry*)malloc(sizeof(t_geometry));
	if (!geo)
		mlxyz_crash("Broken malloc");
	geo->vertices = cube_vertices(x, y, z);
	geo->edges = cube_edges(geo->vertices);
	geo->faces = cube_faces(geo->edges);
	return (geo);
}
