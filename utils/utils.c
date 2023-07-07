/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:09:47 by viktortr          #+#    #+#             */
/*   Updated: 2023/07/07 11:19:34 by viktortr         ###   ########.fr       */
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

void	get_data(char **av, t_table *table)
{
	table->num_philo = (ft_atoi(av[1]));
	table->time_to_die = (ft_atoi(av[2]) * 1000);
	table->time_to_eat = (ft_atoi(av[3]) * 1000);
	table->time_to_sleep = (ft_atoi(av[4]) * 1000);
    // table->meals_to_eat = ft_atoi(av[5]);
}
