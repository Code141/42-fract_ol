/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:31:02 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 18:31:13 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "mlx.h"
# include "ctx.h"
# include "x11_events.h"
# include "keyboard.h"
# include "mouse.h"
# include "loop.h"

int		hooks(t_ctx *ctx);

#endif
