#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void handler(int sig, siginfo_t *info, void *oinfo)
{
    static unsigned char c;
    static int i;
    static pid_t c_pid;
    static char buf[9984];
    static int n;

    if (c_pid == 0)
        c_pid = info->si_pid;
    // if (info->si_pid == c_pid)
    //     kill(c_pid, SIGUSR1);
    // else
    // {
    //     kill(info->si_pid, SIGUSR2);
    //     kill(c_pid, SIGUSR1);
    // }
    c |= (sig == SIGUSR1);
    if (i++ == 7)
    {
        i = 0;
        buf[n++] = c;
        if (n == 9984)
        {
            ft_putstr_fd(buf, 1);
            ft_bzero(buf, 9984);
            n = 0;
        }
        else if (c == 0)
        {
            buf[n] = 0;
            ft_putendl_fd(buf, 1);
            ft_bzero(buf, 9984);
            n = 0;
            usleep(20);
            kill(c_pid, SIGUSR2);
            c_pid = 0;
            return;
        }
        c = 0;
    }
    else
        c <<= 1;
    usleep(20);
    kill(c_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction act;

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler;
    // sigemptyyset;
    // sigaddset(SIG1, SIG2);
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1)
        pause();
    return (0);
}
