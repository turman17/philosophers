/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:04:41 by viktortr          #+#    #+#             */
/*   Updated: 2023/09/07 14:32:58 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	checker_ac(int ac)
{
	if (ac >= 5 && ac <= 6)
		return (0);
	else
	{
		printf("Invalid amount of arguments\n");
		exit(1);
	}
	return (0);
}

int	checker_av(int ac, char **av)
{
	int	i;
	int	y;

	i = 1;
	checker_ac(ac);
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
					exit(1);
				}
			}
			y++;
		}
		i++;
	}
	return (0);
}
