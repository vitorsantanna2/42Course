/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:10:56 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/14 17:18:29 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int		id;
	char 	*name;
	void	*next;
} t_philo;

typedef struct s_saloon
{
	int			number_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_times;
	pthread_t 	*threads;
	t_philo		philo;
} t_saloon;

int	atoi(char *str);

#endif
