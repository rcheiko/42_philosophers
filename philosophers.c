/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:51:41 by rcheiko           #+#    #+#             */
/*   Updated: 2021/07/21 17:17:32 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_total	d;
	int		i;

	if (error(ac, av) == 1)
		return (1);
	fill_struct(ac, av, &d);
	i = -1;
	if (d.nb_philo != 1)
	{
		while (++i < d.nb_philo)
			pthread_detach(d.ph[i].phil);
		free(g_mut);
		free(d.ph);
	}
	return (1);
}
