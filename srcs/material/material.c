/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:23:59 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/01 12:24:00 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ctx.h"
#include "material.h"

t_material		*new_material(t_color_rgba color)
{
	t_material	*material;

	material = (t_material*)malloc(sizeof(t_material));
	if (!material)
		crash("Broken malloc");
	material->color = color;
	return (material);
}

t_color_rgba	material_get_color(void)
{
	t_color_rgba	c;

	c.hex = 0x000000;
	return (c);
}

void			destroy_material(t_material *material)
{
	free(material);
}
