/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:37:25 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object/scene.h>
#include <core/core.h>

t_scene		*new_scene(void)
{
	t_scene *scene;

	scene = (t_scene*)malloc(sizeof(t_scene));
	if (!scene)
		mlxyz_crash("Broken malloc");
	scene->objects = NULL;
	return (scene);
}

void		scene_add(t_scene *scene, t_object *object)
{
	ft_lst_push_back(&scene->objects, ft_lst_new_link(object));
}

void		destroy_scene(t_scene *scene)
{
	ft_lstdel(&scene->objects, &destroy_objects);
	free(scene);
}
