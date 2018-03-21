/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:57:30 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 19:53:59 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include <stdlib.h>
# include <libft.h>
# include <math/vector.h>
# include <object/object.h>
# include <object/mesh.h>

typedef struct	s_scene
{
	t_list		*objects;
}				t_scene;

t_scene			*new_scene();
void			scene_add(t_scene *scene, t_object *object);
void			destroy_scene(t_scene *scene);

#endif
