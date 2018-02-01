/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:26:45 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/18 09:51:22 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "mlx.h"
# include "libft.h"
# include "ctx.h"
# include "draw.h"
# include "draw_hud.h"

void	update_all(t_ctx *ctx, t_list *object);
int		loop(t_ctx *ctx);

#endif
