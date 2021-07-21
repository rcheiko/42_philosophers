/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:38:36 by rcheiko           #+#    #+#             */
/*   Updated: 2021/07/19 16:27:01 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac != 5 && ac != 6)
	{
		printf("Error number of arguments.\n");
		return (1);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (char_digit(av[i][j]) == 0)
			{
				printf("Error bad character !\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
