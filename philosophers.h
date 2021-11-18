/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:20:38 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/21 23:18:32 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

pthread_mutex_t	*g_mut;
pthread_mutex_t	g_death;
pthread_mutex_t	g_write;

typedef struct s_philo
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				id;
	int				nb_eat;
	int				nb_eat_total;
	long			last_eat;
	long			time;
	pthread_t		phil;
}				t_philo;

typedef struct s_total
{
	int		nb_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_eat_total;
	t_philo	*ph;
}				t_total;

//atoi
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
//itoa
char		*ft_itoa(int n);
//utils
int			ft_strlen(const char *str);
int			char_digit(char c);
void		ft_usleep(int ms);
long int	actual_time(void);
//error
int			error(int ac, char **av);
int			error_2(int ac, char **av);
//fill_struct
void		fill_struct(int ac, char **av, t_total *d);
void		fill_struct_2(int ac, char **av, int i, t_total *d);
//THREAD FCT
void		*thread_crea(void *arg);
void		eat(t_philo *ph);
void		sleep_philo(t_philo *ph);
void		think(t_philo *ph);
void		*death_philo(void *arg);
int			check_death(t_philo *ph, int i);
int			count_nb_eat_total(t_philo *ph);
//time
long int	get_time(void);
//msg
void		print_fork(t_philo *ph);
void		print_sleep(t_philo *ph);
void		print_think(t_philo *ph);
#endif
