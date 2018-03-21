/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:52 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/16 19:37:08 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <color/s_color_rgba.h>

t_color_rgba		color_blend(
						t_color_rgba *ca, t_color_rgba *cb, float balance);
unsigned char		color_canal_sub(unsigned char base, unsigned char value);
unsigned char		color_canal_add(unsigned char base, unsigned char value);
t_color_rgba		color_sub(t_color_rgba base, t_color_rgba value);
t_color_rgba		color_add(t_color_rgba base, t_color_rgba value);

#endif
