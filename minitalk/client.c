#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void handler(int sig, siginfo_t *info, void *oinfo)
{
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("Fail!", 1);
		ft_putstr_fd("\n", 1);
		exit(1);
	}
}

int main(int ac, char **av)
{
    int				i;
	char			*str;
	struct sigaction act;

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
	str = av[2];
    while (*str)
    {
		i = 7;
		while (i >= 0)
		{
        	if (*str & (1 << i))
			{
            	kill(ft_atoi(av[1]), SIGUSR1);
			}
        	else
			{
            	kill(ft_atoi(av[1]), SIGUSR2);
			}
			// usleep(20);
			pause();
        	--i;
		}
		++str;
    }
	i = 7;
	while (i >= 0)
	{
        if ('\n' & (1 << i))
            kill(ft_atoi(av[1]), SIGUSR1);
        else
	    	kill(ft_atoi(av[1]), SIGUSR2);
		// usleep(20);
		pause();
        --i;
	}
	ft_putendl_fd("Success!", 1);
    return (0);
}