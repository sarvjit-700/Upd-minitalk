/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:36 by ssukhija          #+#    #+#             */
/*   Updated: 2025/01/28 15:00:36 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putpid(pid_t n)
{
	if (n > 9)
	{
		ft_putpid(n / 10);
		ft_putpid(n % 10);
	}
	else
		write(1, &"0123456789"[n % 10], 1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned long	i;

	i = 0;
	if (fd < 0)
		return ;
	if (s == NULL)
		write (fd, "(NULL)", 6);
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new_str = (char *) malloc((i + j + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(s1);
	return (new_str);
}

int	ft_atoi(const char *nptr)
{
	long long	num;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	num = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
			i++;
		}
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = (num * 10) + (nptr[i] - 48);
		i++;
	}
	num *= sign;
	return (num);
}