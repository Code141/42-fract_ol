/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:56:40 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 19:21:11 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include <math.h>
# include <core/core.h>
# include <color/color.h>

void	put_pixel(t_img *canevas, int x, int y, t_color_rgba color);
void	draw_point(t_img *canevas, t_vector2 v, int size, t_color_rgba color);

#endif
