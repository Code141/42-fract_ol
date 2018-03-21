/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_color_rgba.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:52 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 21:32:45 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_COLOR_RGBA_H
# define S_COLOR_RGBA_H

typedef union		u_color_rgba
{
	unsigned int	hex;
	struct			s_c
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}				c;
}					t_color_rgba;

#endif
