/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpichon <gpichon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:13:16 by gebz              #+#    #+#             */
/*   Updated: 2025/02/24 15:54:57 by gpichon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 5)
	{
		init_value_five(data, av);
		init_loop();
	}
	return (0);
}

void	init_value_five(t_data data, char **av)
{
	int	i;

	i = 0;
	data.philo.nb_philo = ft_atoi_philo(av[1]);
	gettimeofday(&data.philo.tv, NULL);
	// mettre le temps en millisecondes  long long milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	data.tab_philo = malloc(sizeof(t_data) * data.philo.nb_philo - 1);
	while (i < data.philo.nb_philo)
	{
		init_philo(data, av, i);
	}
	init_fork();
}

void	init_philo(t_data data, char **av, int id)
{
	data.philo.time_to_die = ft_atoi_philo(av[2]);
	data.philo.time_to_eat = ft_atoi_philo(av[3]);
	data.philo.time_to_sleep = ft_atoi_philo(av[4]);
	data.philo.philosopher_id = id + 1;
	data.philo.eat = 0;
	if (av[6])
		data.philo.nbr_of_eat = ft_atoi_philo(av[5]);
	else
		data.philo.nbr_of_eat = NULL;
}
