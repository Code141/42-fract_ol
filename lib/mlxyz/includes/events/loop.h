/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:26:45 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 16:14:19 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include <mlx.h>
# include <libft.h>
# include <core/core.h>
# include <draw/draw.h>
# include <draw/draw_hud.h>

void	update_all(t_mlxyz *mlxyz, t_list *object);
int		loop(t_mlxyz *mlxyz);

#endif
