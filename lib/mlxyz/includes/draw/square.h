/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:19:01 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 19:52:48 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H
# include <math/pixel.h>

void	square(t_img *canevas, t_vector2 v1, t_vector2 v2, unsigned int color);
void	square_full(t_img *canevas, t_vector2 v1, t_vector2 v2,
			unsigned int color);

#endif
