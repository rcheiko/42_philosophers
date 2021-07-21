/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:37:33 by rcheiko           #+#    #+#             */
/*   Updated: 2021/07/19 15:51:54 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_time(void)
{
	struct timeval	tval;
	long int		total;

	gettimeofday(&tval, NULL);
	total = (tval.tv_sec * 1000) + (tval.tv_usec / 1000);
	return (total);
}
