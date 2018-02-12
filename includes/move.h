/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:50:50 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/12 03:52:01 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include <mlxyz.h>
# include <fractol.h>

void	fractol_move(t_mlxyz *mlxyz, t_fractol *fractol, int x, int y);
void	fractol_zoom_in(t_mlxyz *mlxyz, t_fractol *fractol);
void	fractol_zoom_out(t_mlxyz *mlxyz, t_fractol *fractoli);

#endif
