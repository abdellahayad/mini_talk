/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:40:48 by aayad             #+#    #+#             */
/*   Updated: 2025/03/01 09:40:48 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit_index = 0;
	static char		character = 0;
	static int		pid;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit_index = 0;
		character = 0;
	}
	if (sig == SIGUSR1)
		character |= (0 << bit_index);
	else if (sig == SIGUSR2)
		character |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (character == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &character, 1);
		bit_index = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_putstr_fd("Error\n", 2), 1);
	while (1)
		pause();
}
