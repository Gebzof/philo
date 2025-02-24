/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:12:45 by gebz              #+#    #+#             */
/*   Updated: 2025/02/24 15:52:57 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval
{
	long	tv_sec;
	long	tv_usec;
}	t_time;

typedef struct s_philo
{
	int				philosopher_id;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_eat;
	int				eat;
	struct timeval	tv;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
}	t_philo;

typedef struct s_data
{
	char	*tab_philo;
	t_philo	philo;
}	t_data;


// philo main
int		ft_atoi_philo(const char *str);
void	init_fork(void);
void	init_philo(t_data data, char **av, int id);

// utils
void	init_value(t_data philo, char **av);

#endif