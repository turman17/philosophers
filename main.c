/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:09:03 by viktortr          #+#    #+#             */
/*   Updated: 2023/07/06 21:20:49 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int philo_init(t_table *table)
{
    int i = 0;

    table->philos = malloc(table->num_philo * sizeof(t_philo));
    table->forks = malloc(table->num_philo * sizeof(pthread_mutex_t));

    if (table->philos == NULL || table->forks == NULL)
        return (1);

    // Initialize mutexes for forks
    while (i < table->num_philo) {
        pthread_mutex_init(&table->forks[i], NULL);
        i++;
    }

    i = 0;

    while(i < table->num_philo) {
        table->philos[i].id = i;

        // Set fork pointers. If the philosopher is the last one, the right fork will be the first one.
        table->philos[i].left_fork = &table->forks[i];
        table->philos[i].right_fork = &table->forks[(i+1)%table->num_philo];

        // Create threads
        pthread_create(&table->philos[i].thread_id, NULL, philo, &table->philos[i]);
        i++;
    }

    i = 0;

    // Wait for all threads to finish
    while(i < table->num_philo) {
        pthread_join(table->philos[i].thread_id, NULL);
        i++;
    }

    // Free resources
    free(table->philos);
    free(table->forks);

    return (0);
}


int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5)
	{
		get_data(av, &table);
		philo_init(&table);
	}
	return (0);
}

// {
// 	int			tmp;
// 	pthread_t	thread;

// 	tmp = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_create(&thread, 0, eat, &tmp);
// 	pthread_join(thread, 0);
// 	pthread_mutex_lock(&mutex);
// 	printf("%d\n", tmp);
// 	pthread_mutex_unlock(&mutex);
// 	pthread_mutex_destroy(&mutex);
// 	return (0);
// }

//arguments: number_of_philosophers | time_to_die | time_to_eat | time_to_sleep