/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:55:12 by viktortr          #+#    #+#             */
/*   Updated: 2023/09/07 17:11:55 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_dead(t_philo *philo)
{
	unsigned long	current_time;

	current_time = get_time();
	pthread_mutex_lock(&philo->table->waiter);
	if (philo->table->flag == 1)
	{
		pthread_mutex_unlock(&philo->table->waiter);
		return (1);
	}
	if ((current_time - philo->last_ate) >= (unsigned long)(philo->time_to_die))
	{
		philo->table->flag = 1;
		pthread_mutex_lock(&philo->table->write);
		printf("%ld		%d		died\n", (current_time - philo->last_ate),
			philo->id);
		pthread_mutex_unlock(&philo->table->write);
		pthread_mutex_unlock(&philo->table->waiter);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->waiter);
	return (0);
}

void	philo_is_eating(t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	start_eating_time;

	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(&philo->table->write);
	current_time = get_time();
	printf("%ld		%d		is eating\n", (current_time - philo->init_time),
		philo->id);
	pthread_mutex_unlock(&philo->table->write);
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
	philo->meals_to_eat--;
	if(philo->meals_to_eat == 0)
	{
		pthread_mutex_lock(&philo->table->waiter);
		philo->table->flag = 1;
		pthread_mutex_unlock(&philo->table->waiter);
	}
	philo->last_ate = get_time();
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_forks(t_philo *philo)
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

void	ft_sleep(t_philo *philo)
{
	unsigned long	start_sleeping_time;
	unsigned long	current_time;

	current_time = get_time();
	if (!is_dead(philo))
	{
		pthread_mutex_lock(&philo->table->write);
		printf("%ld		%d		is sleeping\n", (current_time
				- philo->init_time), philo->id);
		pthread_mutex_unlock(&philo->table->write);
		start_sleeping_time = get_time();
		while ((get_time() - start_sleeping_time) < (long unsigned int)
			philo->time_to_sleep)
		{
			if (is_dead(philo))
				return ;
			usleep(1);
		}
	}
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_ate = get_time();
	philo->init_time = get_time();
	if (philo->id % 2 == 0 && philo->id != 1)
		usleep(5000);
	while (1)
	{
		if (is_dead(philo))
			break ;
		take_forks(philo);
		philo_is_eating(philo);
		if (is_dead(philo))
			break ;
		ft_sleep(philo);
		if (is_dead(philo))
			break ;
	}
	return (NULL);
}
