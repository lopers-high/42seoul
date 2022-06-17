/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:17:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/17 21:12:43 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	handler(int sig, siginfo_t *info, void *oinfo)
{
	static int	count;

	(void)info;
	(void)oinfo;
	if (sig == SIGUSR1)
		++count;
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("Received Byte: ", 1);
		ft_putnbr_fd((count - 7) / 8, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	check_argument(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putendl_fd("Invalid Argument.", 1);
		return (0);
	}
	if (*av[2] == '\0')
	{
		ft_putendl_fd("Input Message.", 1);
		return (0);
	}
	if (ft_minitalk_atoi(av[1]) < 100 || ft_minitalk_atoi(av[1]) > 99998)
	{
		ft_putendl_fd("Invalid PID.", 1);
		return (0);
	}
	return (1);
}

void	send_byte(char *msg, int s_pid)
{
	int		i;

	usleep(20);
	i = 7;
	while (i >= 0)
	{
		if (*msg & (1 << i))
		{
			if (kill(s_pid, SIGUSR1) == -1)
			{
				ft_putendl_fd("BAD SIGNAL!!", 1);
				exit(0);
			}
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
			{
				ft_putendl_fd("BAD SIGNAL!!", 1);
				exit(0);
			}
		}
		pause();
		--i;
	}
}

void	send_eof(int s_pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		usleep(20);
		if (kill(s_pid, SIGUSR2) == -1)
		{
			ft_putendl_fd("BAD SIGNAL!!", 1);
			exit(0);
		}
		pause();
		--i;
	}
}

int	main(int ac, char **av)
{
	char				*msg;
	struct sigaction	act;
	int					s_pid;

	if (!check_argument(ac, av))
		return (0);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	ft_putstr_fd("Sent Byte: ", 1);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	msg = av[2];
	s_pid = ft_minitalk_atoi(av[1]);
	while (*msg)
	{
		send_byte(msg, s_pid);
		++msg;
	}
	send_eof(s_pid);
	return (0);
}
