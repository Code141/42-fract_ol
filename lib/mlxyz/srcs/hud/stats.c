/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:22:13 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 17:11:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hud/stats.h>
#include <core/core.h>

t_stats	*new_stats(void)
{
	t_stats			*stats;
	struct timeval	tv;

	stats = (t_stats*)malloc(sizeof(t_stats));
	if (!stats)
		mlxyz_crash("Broken malloc");
	stats->timestamp = (int)time(NULL);
	ft_bzero(stats->fps, 100 * 4);
	ft_bzero(stats->ms, 100 * 4);
	gettimeofday(&tv, NULL);
	stats->timestamp = (unsigned long long)(tv.tv_sec) * 1000
		+ (unsigned long long)(tv.tv_usec) / 1000;
	stats->last = stats->timestamp;
	stats->frame = 0;
	return (stats);
}

void	array_shift_right(int *array, int size)
{
	while (size > 1)
	{
		array[size - 1] = array[size - 2];
		size--;
	}
}

void	refresh_stats(t_stats *stats)
{
	struct timeval		tv;
	unsigned long long	now;

	gettimeofday(&tv, NULL);
	stats->timestamp_m = (unsigned long long)(tv.tv_usec) / 1000;
	now = (unsigned long long)(tv.tv_sec) * 1000
		+ (unsigned long long)(tv.tv_usec) / 1000;

	stats->frame++;
	if (stats->timestamp + 1000 < now)
	{
		stats->timestamp = now;
		array_shift_right(stats->fps, 100);
		stats->fps[0] = stats->frame;
		stats->frame = 0;
	}
	array_shift_right(stats->ms, 100);
	stats->ms[0] = now - stats->last;
	stats->last = now;
}
