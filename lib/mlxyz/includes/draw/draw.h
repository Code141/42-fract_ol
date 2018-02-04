/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:50 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 16:59:02 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <core/core.h>
# include <math/vector.h>
# include <math/matrice4.h>
# include <math/pixel.h>
# include <hud/hud.h>
# include <draw/draw_mesh.h>
# include <draw/bresenham_line.h>

int			projection(t_mlxyz *mlxyz, t_vector4 *v1, t_vector2 *v2);
void		draw_all(t_mlxyz *mlxyz, t_list *elements, t_matrice4 *m);
void		render(t_mlxyz *mlxyz);
void		draw_hud(t_mlxyz *mlxyz);

#endif
