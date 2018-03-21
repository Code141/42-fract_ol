/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:35:28 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/21 13:51:38 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <fractol_struct.h>
# include <mlxyz.h>

unsigned int	color(t_pixel *pixel, double cindice);
void			iterations(int id, t_pixel *pixel);

#endif
