/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:04:41 by viktortr          #+#    #+#             */
/*   Updated: 2023/09/09 12:42:13 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_0(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) == 0)
		{
			printf("Invalid format of argument\n");
			return (1);
		}
	}
	if (ac >= 5 && ac <= 6)
		return (0);
	else
	{
		printf("Invalid amount of arguments\n");
		return (1);
	}
	return (0);
}

int	checker_av(int ac, char **av)
{
	int	i;
	int	y;

	i = 1;
	if (check_0(ac, av) == 1)
		return (1);
	while (i < ac)
	{
		y = 0;
		while (av[i][y])
		{
			if (av[i][y] < '0' || av[i][y] > '9')
			{
				if (av[i][y] != '\t' && av[i][y] != ' ' && av[i][y] != '+')
				{
					printf("Invalid format of argument\n");
					return (1);
				}
			}
			y++;
		}
		i++;
	}
	return (0);
}

void	lock_left_fork(t_philo *philo)
{
	unsigned long	current_time;

	pthread_mutex_lock(philo->left_fork);
	if (!is_dead(philo))
	{
		pthread_mutex_lock(&philo->table->write);
		current_time = get_time();
		printf("%ld		%d		has taken a fork\n", (current_time
				- philo->init_time), philo->id);
		pthread_mutex_unlock(&philo->table->write);
	}
}

void	lock_right_fork(t_philo *philo)
{
	unsigned long	current_time;

	pthread_mutex_lock(philo->right_fork);
	if (!is_dead(philo))
	{
		pthread_mutex_lock(&philo->table->write);
		current_time = get_time();
		printf("%ld		%d		has taken a fork\n", (current_time
				- philo->init_time), philo->id);
		pthread_mutex_unlock(&philo->table->write);
	}
}

void	eating_(t_philo *philo)
{
	unsigned long	start_eating_time;

	start_eating_time = get_time();
	while ((get_time()
			- start_eating_time) < (long unsigned int)philo->time_to_eat)
	{
		if (is_dead(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		usleep(1);
	}
	philo->table->meals_to_eat--;
	if (philo->table->meals_to_eat == 0)
	{
		pthread_mutex_lock(&philo->table->waiter);
		philo->table->flag = 1;
		pthread_mutex_unlock(&philo->table->waiter);
	}
	philo->last_ate = get_time();
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
