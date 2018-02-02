/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:37:05 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:56:55 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object/camera.h>
#include <ctx.h>

t_camera	*new_camera(float angle, float near, float far)
{
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	if (!camera)
		crash("Broken malloc");
	set_point(0, 0, 0, &camera->pos);
	set_angle(0, 0, 0, &camera->rot);
	camera->angle = angle;
	camera->near = near;
	camera->far = far;
	camera->fog_color.hex = 0x000000;
	return (camera);
}

void		destroy_camera(t_camera *cam)
{
	free(cam);
}
