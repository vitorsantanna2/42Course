/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:43:33 by jsantann          #+#    #+#             */
/*   Updated: 2022/08/23 20:23:53 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minitalk.h"

void	convert_char_to_bit(unsigned char octet, pid_t pid)
{
	int	counter;

	counter = 8;
	while (counter-- > 0)
	{
		if (!(octet & 0x80))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		octet = octet << 1;
	}
}

void	handler_sigusr(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("%s\n", "ℹ️  Signal received\n");
}

int	main(int argc, char *argv[])
{	
	int		counter;
	pid_t	pid;

	signal(SIGUSR2, handler_sigusr);
	signal(SIGUSR1, handler_sigusr);
	counter = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (1);
	while (argv[2][counter])
	{
		convert_char_to_bit(argv[2][counter], pid);
		counter++;
	}
	convert_char_to_bit(argv[2][counter], pid);
	return (0);
}
