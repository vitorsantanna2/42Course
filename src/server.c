/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:25:37 by jsantann          #+#    #+#             */
/*   Updated: 2022/08/23 20:46:36 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libraries/minitalk.h"

void	handler_sigusr(int signum, siginfo_t *info, void *unused)
{
	static int	counter = 0;
	static char	c = 0xFF;

	(void)*unused;
	if (signum == SIGUSR2)
		c |= 0x80 >> counter;
	else if (signum == SIGUSR1)
		c ^= 0x80 >> counter;
	if (++counter == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		counter = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	pid_t				pid_id;
	struct sigaction	structer;

	pid_id = getpid();
	structer.sa_sigaction = &handler_sigusr;
	sigemptyset(&structer.sa_mask);
	structer.sa_flags = SA_SIGINFO;
	ft_printf("✅ Pid: %d\n", pid_id);
	sigaction(SIGUSR1, &structer, NULL);
	sigaction(SIGUSR2, &structer, NULL);
	while (1)
		pause();
}
