/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:26:14 by rcheiko           #+#    #+#             */
/*   Updated: 2021/07/21 17:08:37 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_fork(t_philo *ph)
{
	pthread_mutex_lock(&g_write);
	usleep(50);
	printf("%ld %d has taken a fork\n", get_time() - ph->time, ph->id);
	printf("%ld %d has taken a fork\n", get_time() - ph->time, ph->id);
	printf("%ld %d is eating\n", get_time() - ph->time, ph->id);
	pthread_mutex_unlock(&g_write);
}

void	print_sleep(t_philo *ph)
{
	pthread_mutex_lock(&g_write);
	usleep(50);
	printf("%ld %d is sleeping\n", get_time() - ph->time, ph->id);
	pthread_mutex_unlock(&g_write);
}

void	print_think(t_philo *ph)
{
	pthread_mutex_lock(&g_write);
	usleep(50);
	printf("%ld %d is thinking\n", get_time() - ph->time, ph->id);
	pthread_mutex_unlock(&g_write);
}
