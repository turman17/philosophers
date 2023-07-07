/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:55:12 by viktortr          #+#    #+#             */
/*   Updated: 2023/07/05 14:01:09 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
    if(philo->id % 2 == 0)
        usleep(1000);
    while (1)
    {
        pthread_mutex_lock(philo->left_fork);
        printf("%d %d has taken a fork\n", philo->id, philo->id);
    }
	return (0);
}