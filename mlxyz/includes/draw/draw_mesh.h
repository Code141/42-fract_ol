/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mesh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:01 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 16:14:19 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MESH_H
# define DRAW_MESH_H
# include <core/core.h>
# include <draw/draw.h>
# include <draw/bresenham_line.h>

void	draw_mesh(t_mlxyz *mlxyz, t_object *object, t_matrice4 *m);

#endif
