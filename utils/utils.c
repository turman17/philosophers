/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:09:47 by viktortr          #+#    #+#             */
/*   Updated: 2023/09/08 22:19:57 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(char *str)
{
	long	i;
	long	res;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

unsigned long	get_time(void)
{
	unsigned long	ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000UL) + (tv.tv_usec / 1000UL);
	return (ms);
}

void	checker_if_dead(t_philo *philo)
{
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
}

void	is_thinking(t_philo *philo)
{
	unsigned long	current_time;

	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->write);
	current_time = get_time();
	printf("%ld		%d		Is thinking\n", (current_time - philo->init_time),
		philo->id);
	pthread_mutex_unlock(&philo->table->write);
}
