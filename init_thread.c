/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:57:15 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/21 23:13:19 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_crea(void *arg)
{
	t_philo	*ph;

	ph = arg;
	ph->time = get_time();
	if (ph->id % 2 != 0)
		ft_usleep(ph->t_eat);
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
	if (ph->nb_eat == ph->nb_eat_total)
		return ;
	if (ph->id == 0)
		pthread_mutex_lock(&g_mut[ph->nb_philo - 1]);
	else
		pthread_mutex_lock(&g_mut[ph->id - 1]);
	pthread_mutex_lock(&g_mut[ph->id]);
	print_fork(ph);
	ph->nb_eat++;
	ph->last_eat = get_time() - ph->time;
	ft_usleep(ph->t_eat);
	if (ph->id == 0)
		pthread_mutex_unlock(&g_mut[ph->nb_philo - 1]);
	else
		pthread_mutex_unlock(&g_mut[ph->id - 1]);
	pthread_mutex_unlock(&g_mut[ph->id]);
}

void	sleep_philo(t_philo *ph)
{
	print_sleep(ph);
	ft_usleep(ph->t_sleep);
}

void	think(t_philo *ph)
{
	print_think(ph);
}

void	*death_philo(void *arg)
{
	int		i;
	int		count;
	t_philo	*ph;

	ph = arg;
	while (1)
	{
		count = count_nb_eat_total(ph);
		i = 0;
		while (ph[i].nb_philo - 1 > i)
		{
			if (check_death(ph, i) == 1)
				return (NULL);
			i++;
		}
		if (count == ph[0].nb_philo)
		{
			pthread_mutex_lock(&g_write);
			pthread_mutex_unlock(&g_death);
			return (NULL);
		}
	}
}
