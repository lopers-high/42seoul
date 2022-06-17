#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <time.h>

void handler(int sig, siginfo_t *info, void *oinfo)
{
	static int count;

	if (sig == SIGUSR1)
		++count;
	else
	{
		ft_putstr_fd("Received Byte: ", 1);
		ft_putnbr_fd((count - 7) / 8, 1);
		ft_putchar_fd('\n', 1);
	}
}

int check_argument(int ac, char **av)
{
	if (ac != 3)
		;

	if (*av[2] = '\0')
		;

	if (ft_atoi(av[1]) < 100 || ft_atoi(av[1]) > 99998)
		;
}
int main(int ac, char **av)
{
	int i;
	char *msg;
	struct sigaction act;
	int s_pid;
	double start, end;

	start = (double)clock() / CLOCKS_PER_SEC;
	if (ac != 3 || av[2][0] == 0)
	{
		ft_putstr_fd("Invalid Argument", 1);
		return (1);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;

	ft_putstr_fd("Client PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Sent Byte: ", 1);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putstr_fd("\n", 1);

	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	msg = av[2];
	s_pid = ft_atoi(av[1]);
	while (*msg)
	{
		usleep(10);
		i = 7;
		while (i >= 0)
		{
			if (*msg & (1 << i))
			{
				kill(s_pid, SIGUSR1);
			}
			else
			{
				kill(s_pid, SIGUSR2);
			}
			pause();
			--i;
		}
		++msg;
	}
	i = 7;
	while (i >= 0)
	{
		usleep(10);
		kill(s_pid, SIGUSR2);
		pause();
		--i;
	}
	end = (double)clock() / CLOCKS_PER_SEC;
	printf("Operation Time: %lf\n", end - start);
	return (0);
}