/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:57:15 by rcheiko           #+#    #+#             */
/*   Updated: 2021/07/21 17:20:18 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_crea(void *arg)
{
	t_philo	*ph;

	ph = arg;
	ph->time = get_time();
	while (1)
	{
		eat(ph);
		sleep_philo(ph);
		think(ph);
	}
	return (NULL);
}

void	eat(t_philo *ph)
{
	dead_philo(ph);
	if (ph->id == 0)
		pthread_mutex_lock(&g_mut[ph->nb_philo - 1]);
	else
		pthread_mutex_lock(&g_mut[ph->id - 1]);
	pthread_mutex_lock(&g_mut[ph->id]);
	print_fork(ph);
	ph->nb_eat++;
	ph->last_eat = get_time() - ph->time;
	usleep(ph->t_eat * 1000);
	if (ph->id == 0)
		pthread_mutex_unlock(&g_mut[ph->nb_philo - 1]);
	else
		pthread_mutex_unlock(&g_mut[ph->id - 1]);
	pthread_mutex_unlock(&g_mut[ph->id]);
	usleep(100);
}

void	sleep_philo(t_philo *ph)
{
	dead_philo(ph);
	print_sleep(ph);
	usleep(ph->t_sleep * 1000);
}

void	think(t_philo *ph)
{
	dead_philo(ph);
	print_think(ph);
}

void	dead_philo(t_philo *ph)
{
	if ((get_time() - ph->time) - ph->last_eat > ph->t_die && g_d == 0)
	{
		g_d = 1;
		pthread_mutex_lock(&g_write);
		usleep(3000);
		printf("%ld %d dead\n", get_time() - ph->time, ph->id);
		pthread_mutex_unlock(&g_death);
		usleep(1000);
	}
	if (ph->nb_eat_total != -1 && ph->nb_eat >= ph->nb_eat_total)
	{
		pthread_mutex_lock(&g_write);
		usleep(1000);
		pthread_mutex_unlock(&g_death);
		usleep(1000);
	}
}
