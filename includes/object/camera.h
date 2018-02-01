/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:52 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 15:20:26 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vector.h"
# include "color.h"

typedef struct	s_camera
{
	t_vector4		pos;
	t_vector4		rot;
	float			angle;
	float			near;
	float			far;
	t_color_rgba	fog_color;
}				t_camera;

t_camera		*new_camera(float angle, float near, float far);
void			destroy_camera(t_camera *cam);

#endif
