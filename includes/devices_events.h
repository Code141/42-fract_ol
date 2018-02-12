/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devices_events.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:56:30 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/12 03:56:32 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEVICES_EVENTS_H
# define DEVICES_EVENTS_H

#include <mlxyz.h>
#include <fractol.h>

void	refresh_keyboard(t_mlxyz *mlxyz, t_fractol *fractol);
void	refresh_mouse(t_mlxyz *mlxyz, t_fractol *fractol);
void	refresh_input_devices(t_mlxyz *mlxyz, t_fractol *fractol);

#endif
