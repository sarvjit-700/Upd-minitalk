/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:45:59 by ssukhija          #+#    #+#             */
/*   Updated: 2025/01/29 21:45:59 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int ready = 0;

static void received(int sig)
{
    if (sig == SIGUSR1)
        ready = 1;
    if (sig == SIGUSR2)
        exit(write(1, " - Message Received! - \n", 24));
}

static void binary(int pid, char c)
{
    int bitnum;

    bitnum = 0;
    while (bitnum < 8)
    {
        ready = 0;
        if ((c & (0x01 << bitnum)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (ready == 0)
            pause();
        bitnum++;
        usleep(50);
    }
}

static void message(int pid, char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        binary(pid, str[i++]);
    binary(pid, '\0');
}

int main(int argc, char **argv)
{
    int i;
    int pid;
    struct  sigaction sa;

    i = 0;
    if (argc != 3)
        exit(write(1, "Please use the format ./client PID 'text'\n", 42));
    while (argv[1][i] != '\0')
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            exit(write(1, "Sorry invalid PID!\n", 19));
        i++;
    }
    pid = ft_atoi(argv[1]);
    sa.sa_handler = received;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    message(pid, argv[2]);
    return (EXIT_SUCCESS);
}
