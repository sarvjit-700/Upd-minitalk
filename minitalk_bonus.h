/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:37:02 by ssukhija          #+#    #+#             */
/*   Updated: 2025/03/06 10:37:11 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putpid(pid_t n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(const char *nptr);
#endif