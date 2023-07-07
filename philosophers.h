/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:23:11 by viktortr          #+#    #+#             */
/*   Updated: 2023/07/05 13:57:31 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_eat;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				is_dead;
	int				last_eat;
	pthread_t		thread_id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*dead;
    pthread_mutex_t	*left_fork;
    pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_table
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*mutex;
	t_philo			*philos;
}					t_table;

void				get_data(char **av, t_table *table);
void				*philo(void *arg);

#endif