/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:10:08 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/14 17:46:40 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void error(void)
{
	printf("Error\n");
	return ;
}

void	filling_saloon(t_saloon *p1,  char **argv)
{
	t_saloon *temp;
	temp = p1;

	temp->number_philo = atoi(argv[1]);
	temp->time_to_die = atoi(argv[2]);
	temp->time_to_eat = atoi(argv[3]);
	temp->time_to_sleep = atoi(argv[4]);
	temp->number_times = atoi(argv[5]);
}

void	start(p1)
{
	(void)p1;
	printf("Start Routine");
}

int	main(int argc, char **argv)
{
	t_saloon p1;
	t_philo philo;
	pthread_t sophist;
	int	i;

	i = 0;
	if (argc < 5)
		error();
	else
	{
		filling_saloon(&p1, argv);
		//pthread_create(&sophist, NULL, &start, &p1);
		//pthread_join(sophist, NULL);
		while (i < p1.number_philo)
		{
			philo.id = i;
			pthread_create(&p1->threads[i], NULL, &start, p1);
			i++;
		}

	}
	return (0);
}
