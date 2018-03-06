/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:35:28 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 14:39:13 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <fractol_struct.h>
# include <mlxyz.h>
# define M_PI_F 3.1415926536

unsigned char	color_canal_sub(unsigned char base, unsigned char value);
unsigned char	color_canal_add(unsigned char base, unsigned char value);
t_color_rgba	color_sub(t_color_rgba base, t_color_rgba value);
t_color_rgba	color_add(t_color_rgba base, t_color_rgba value);
unsigned int	color(t_pixel *pixel, double cindice);
void			iterations(int id, t_pixel *pixel);

#endif
