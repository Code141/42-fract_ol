/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:45:15 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/21 14:57:13 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TXT_H
# define TXT_H
# include <fractol.h>

void	hud(t_mlxyz *mlxyz, t_fractol *fractol);
void	cadre(t_mlxyz *mlxyz);
void	txt_uno(t_mlxyz *mlxyz, t_fractol *fractol);
void	txt_dos(t_mlxyz *mlxyz, t_fractol *fractol);
void	txt_tres(t_mlxyz *mlxyz, t_fractol *fractol);

#endif
