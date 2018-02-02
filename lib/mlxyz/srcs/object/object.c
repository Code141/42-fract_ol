/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:39:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/02 18:57:26 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object/object.h>
#include <ctx.h>

t_object	*new_object(t_mesh *mesh)
{
	t_object	*obj;

	obj = (t_object*)malloc(sizeof(t_object));
	if (!obj)
		crash("Broken malloc");
	obj->parent = NULL;
	obj->children = NULL;
	obj->mesh = mesh;
	set_point(0, 0, 0, &obj->pos);
	set_angle(0, 0, 0, &obj->rot);
	vector4_clear(&obj->scale);
	matrice4_init(&obj->matrice);
	return (obj);
}

void		object_add_child(t_object *obj1, t_object *obj2)
{
	ft_lst_push_back(&obj1->children, ft_lst_new_link(obj2));
	obj2->parent = obj1;
}

void		destroy_objects(void **objects)
{
	t_object	*object;

	object = (t_object*)objects;
	if (object->mesh)
		destroy_mesh(object->mesh);
	if (object->children)
		ft_lstdel(&object->children, &destroy_objects);
	free(object);
}
