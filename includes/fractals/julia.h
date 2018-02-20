/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:23:21 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/20 12:24:20 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H
#include <mlxyz.h>
#include <fractol.h>

void	julia_loop(t_mlxyz *mlxyz, t_fractol *fractol);
int		julia(double c_r, double c_i, int iterations);

#endif
