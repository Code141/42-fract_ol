/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mesh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:01 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 18:30:25 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MESH_H
# define DRAW_MESH_H
# include "ctx.h"
# include "draw.h"
# include "bresenham_line.h"

void	draw_mesh(t_ctx *ctx, t_object *object, t_matrice4 *m);

#endif
