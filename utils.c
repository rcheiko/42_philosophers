/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:42:46 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/05 17:02:29 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	char_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long int	actual_time(void)
{
	long int		time;
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	time = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (time);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = actual_time();
	while ((actual_time() - time) < ms)
		usleep(ms);
}

int	check_death(t_philo *ph, int i)
{
	if ((get_time() - ph[i].time) - ph[i].last_eat > ph[i].t_die)
	{
		pthread_mutex_lock(&g_write);
		printf("%ld %d dead\n", get_time() - ph[i].time, ph[i].id);
		pthread_mutex_unlock(&g_death);
		usleep(1000);
		return (1);
	}
	return (0);
}
