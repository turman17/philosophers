/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:23:11 by viktortr          #+#    #+#             */
/*   Updated: 2023/09/07 17:03:53 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;

	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	unsigned long		last_ate;
	unsigned long		init_time;
	int					time_to_eat;
	t_table				*table;
	int					time_to_sleep;
	pthread_t			thread_id;
	int					time_to_die;
	int					meals_to_eat;
}						t_philo;

typedef struct s_table
{
	int					flag;
	int					init_time;
	int					num_philo;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write;
	pthread_mutex_t		waiter;
}						t_table;

void					*philo(void *arg);
int						ft_atoi(char *str);
unsigned long			get_time(void);
int						checker_av(int ac, char **av);

#endif
