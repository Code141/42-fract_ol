/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:36:00 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 14:21:45 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct	s_fractol
{
	int			win_width;
	int			win_height;

	int			fractal;

	int			render;
	char		lock;


	int			max_iter;
	double		zoom;

	double		x;
	double		y;

	double		color_indice;

	double		cr_custom;
	double		ci_custom;

	int			w_w;
	int			w_h;
	int			w_p_x;
	int			w_p_y;
}				t_fractol;

typedef struct	s_pixel
{
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
