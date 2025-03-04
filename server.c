/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:14:19 by ssukhija          #+#    #+#             */
/*   Updated: 2025/03/04 17:23:59 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*msg;

void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n- INTERRUPTED - Server shutting down...\n", 41);
	if (msg)
		free(msg);
	msg = NULL;
	exit(EXIT_SUCCESS);
}

void	response(int sig, siginfo_t *info, void *context)
{
	(void)context;
	pid_t	c_pid = info->si_pid;
	static int	bitnum = 0;
	static int	i;
	char	c[2];
	
	if (sig == SIGUSR1)
		i |= (0x01 << bitnum);
	bitnum++;
	if (bitnum == 8)
	{
		c[0] = (char)i;
		c[1] = '\0';
		if (msg == NULL)
		{	
			msg = malloc(sizeof(char) * 1);
			if (msg == NULL)
				return ;
			msg[0] = '\0';
		}
		msg = ft_strjoin(msg, c);
		if (c[0] == '\0')
		{
			ft_putstr_fd(msg, 1);
			free(msg);
			msg = NULL;
			write(1,"\n", 1);
			kill(c_pid, SIGUSR2);
		}
		bitnum = 0;
		i = 0;
	}
	usleep(50);
	kill(c_pid, SIGUSR1);
}

int	main(void)
{
	pid_t	pid;
	struct	sigaction sa;
	struct	sigaction sa_int;

	pid = getpid();
	write(1, "SERVER PID : ", 12);
	ft_putpid(pid);
	write(1, "\n", 1);	
	sa.sa_sigaction = response;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sa_int.sa_handler = sigint_handler;
	sa_int.sa_flags = 0;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);
	while (pid)
		pause();
	return (EXIT_SUCCESS);
}
