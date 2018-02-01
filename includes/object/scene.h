/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:57:30 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/17 14:54:24 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "libft.h"
# include "vector.h"
# include "mesh.h"
# include "object.h"

typedef struct	s_scene
{
	t_list		*objects;
}				t_scene;

t_scene			*new_scene();
void			scene_add(t_scene *scene, t_object *object);
void			destroy_scene(t_scene *scene);

#endif
