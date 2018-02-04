/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:31:02 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 16:14:19 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include <mlx.h>
# include <core/core.h>
# include <events/x11_events.h>
# include <events/keyboard.h>
# include <events/mouse.h>
# include <events/loop.h>

int		hooks(t_mlxyz *mlxyz);

#endif
