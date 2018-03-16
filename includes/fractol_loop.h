/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_loop.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:26:45 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/16 18:43:13 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_LOOP_H
# define FRACTOL_LOOP_H
# include <mlxyz.h>
# include <fractol_struct.h>

void	loop_cpu(unsigned int *canevas, t_fractol *fractol);
void	loop_opencl(t_mlxyz *mlxyz, t_fractol *fractol);
void	render_main(t_mlxyz *mlxyz, t_fractol *fractol);
void	render_aux(t_mlxyz *mlxyz, t_fractol fractol);
void	loop(t_mlxyz *mlxyz);

#endif
