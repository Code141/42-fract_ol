/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 09:11:43 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/17 06:29:51 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include <opencl.h>
typedef struct	s_fractol
{
	int			max_iter;
	double		zoom;
	double		x;
	double		y;
	t_opencl	*opencl;
}				t_fractol;

void	fractol(t_mlxyz *mlxyz, t_fractol *fractol);

#endif
