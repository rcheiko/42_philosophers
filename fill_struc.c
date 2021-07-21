/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:59:33 by rcheiko           #+#    #+#             */
/*   Updated: 2021/07/21 17:19:46 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fill_struct(int ac, char **av, t_total *d)
{
	int			i;
	int			k;

	i = 0;
	k = -1;
	g_d = 0;
	if (ac != 6)
		d->nb_eat_total = -1;
	else
		d->nb_eat_total = ft_atoi(av[5]);
	d->nb_philo = ft_atoi(av[1]);
	d->t_die = ft_atoi(av[2]);
	d->t_eat = ft_atoi(av[3]);
	d->t_sleep = ft_atoi(av[4]);
	if (d->nb_philo == 1)
	{
		printf("%ld %d dead\n", get_time() - get_time(), d->nb_philo - 1);
		return ;
	}
	d->ph = malloc(sizeof(t_philo) * (d->nb_philo));
	g_mut = malloc(sizeof (pthread_mutex_t) * (d->nb_philo));
	while (++k < d->nb_philo)
		pthread_mutex_init(&g_mut[k], NULL);
	fill_struct_2(ac, av, i, d);
	pthread_mutex_lock(&g_death);
}

void	fill_struct_2(int ac, char **av, int i, t_total *d)
{
	pthread_mutex_init(&g_death, NULL);
	pthread_mutex_lock(&g_death);
	while (i < d->nb_philo)
	{
		if (ac != 6)
			d->ph[i].nb_eat_total = -1;
		else
			d->ph[i].nb_eat_total = ft_atoi(av[5]);
		d->ph[i].id = i;
		d->ph[i].nb_eat = 0;
		d->ph[i].last_eat = 0;
		d->ph[i].nb_philo = ft_atoi(av[1]);
		d->ph[i].t_die = ft_atoi(av[2]);
		d->ph[i].t_eat = ft_atoi(av[3]);
		d->ph[i].t_sleep = ft_atoi(av[4]);
		d->ph[i].time = get_time();
		pthread_create(&d->ph[i].phil, NULL, &thread_crea, &d->ph[i]);
		usleep(1000);
		i++;
	}
}
