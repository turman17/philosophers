/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:01:09 by viktortr          #+#    #+#             */
/*   Updated: 2023/09/07 17:04:40 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_mutex(t_table *table, char **av, int ac)
{
	int	i;

	i = -1;
	table->flag = 0;
	pthread_mutex_init(&table->waiter, NULL);
	pthread_mutex_init(&table->write, NULL);
	while (++i < table->num_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		table->philos[i].id = i + 1;
		table->philos[i].init_time = table->init_time;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i - 1 + table->num_philo)
			% table->num_philo];
		table->philos[i].table = table;
		table->philos[i].time_to_die = ft_atoi(av[2]);
		table->philos[i].time_to_eat = ft_atoi(av[3]);
		table->philos[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			table->philos[i].meals_to_eat = ft_atoi(av[5]);
		pthread_create(&table->philos[i].thread_id, NULL, (void *)philo,
				&table->philos[i]);
	}
}

int	main(int ac, char **av)
{
	t_table	table;
	int		i;

	checker_av(ac, av);
	table.num_philo = ft_atoi(av[1]);
	table.philos = malloc(table.num_philo * sizeof(t_philo));
	table.forks = malloc(table.num_philo * sizeof(pthread_mutex_t));
	init_mutex(&table, av, ac);
	i = -1;
	while (++i < table.num_philo)
	{
		pthread_join(table.philos[i].thread_id, NULL);
	}
	pthread_mutex_destroy(&table.write);
	pthread_mutex_destroy(&table.waiter);
	i = -1;
	while (++i < table.num_philo)
		pthread_mutex_destroy(&table.forks[i]);
	free(table.philos);
	free(table.forks);
	return (0);
}
