/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxyz.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:57:10 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:00:29 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXYZ_H
# define MLXYZ_H

# define PI 3.14159265
# define RAD PI / 180
# define TO_RAD(x) ((x) * PI / 180.0)
# define TO_DEG(x) ((x) * 180.0 / PI)

# include <libft.h>
# include <mlx.h>

# include <core/core.h>

# include <color/color.h>

# include <screen/screen.h>

# include <geometry/geometry.h>
# include <geometry/plane.h>
# include <geometry/cube.h>
# include <geometry/surface.h>
# include <geometry/surface2.h>

# include <hud/hud.h>
# include <hud/stats.h>
# include <hud/graph.h>

# include <material/material.h>

# include <math/vector.h>
# include <math/matrice4.h>

# include <object/object.h>

# include <object/scene.h>
# include <object/camera.h>
# include <object/mesh.h>

# include <draw/draw.h>
# include <events/events.h>
# include <events/keyboard.h>
# include <events/mouse.h>

#endif
