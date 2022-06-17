/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:17:29 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/17 21:12:40 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

int	print_buf(unsigned char *c, int *i, int *c_pid)
{
	static char				buf[9984];
	static int				n;

	*i = 0;
	buf[n++] = *c;
	if (n == 9984)
	{
		ft_putstr_fd(buf, 1);
		ft_bzero(buf, 9984);
		n = 0;
	}
	else if (*c == 0)
	{
		buf[n] = 0;
		ft_putendl_fd(buf, 1);
		ft_bzero(buf, 9984);
		n = 0;
		usleep(50);
		kill(*c_pid, SIGUSR2);
		*c_pid = 0;
		return (0);
	}
	*c = 0;
	return (1);
}

void	handler(int sig, siginfo_t *info, void *oinfo)
{
	static unsigned char	c;
	static int				i;
	static pid_t			c_pid;

	(void)oinfo;
	if (c_pid == 0)
		c_pid = info->si_pid;
	c |= (sig == SIGUSR1);
	if (i++ == 7)
	{
		if (!print_buf(&c, &i, &c_pid))
			return ;
	}
	else
	{
		c <<= 1;
		usleep(50);
	}
	kill(c_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
