/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:36:00 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 15:27:37 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct	s_fractol
{
	char		*fractal_name;
	int			fractal;
	int			render;
	int			max_iter;
	double		zoom;
	double		x;
	double		y;
	double		color_indice;
	double		cr_custom;
	double		ci_custom;
	char		lock;
}				t_fractol;

typedef struct	s_pixel
{
	int		win_width;
	int		win_height;
	int		width;
	int		height;
	int		x;
	int		y;
	int		index;
	int		max_iter;
	double	cr;
	double	ci;
	double	cr_custom;
	double	ci_custom;
	int		iterations;
	int		value;
	double	pos;
}				t_pixel;

#endif
