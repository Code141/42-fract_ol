/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:46 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 19:18:49 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_LINE_H
# define BRESENHAM_LINE_H
# include <math/pixel.h>

void	line(t_img *canevas, t_vector2 v1, t_vector2 v2, t_color_rgba color);

#endif
