/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:46 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/21 12:22:01 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_H
# define STATS_H
# include <sys/time.h>
# include <stdlib.h>
# include <libft.h>

typedef	struct	s_stats
{
	unsigned long long	timestamp;
	unsigned long long	now;
	unsigned long long	timestamp_ms;
	unsigned long long	last;
	int					fps[100];
	int					ms[100];
	int					frame;
	struct timeval		time;
}				t_stats;

t_stats			*new_stats();
void			refresh_stats(t_stats *stats);

#endif
