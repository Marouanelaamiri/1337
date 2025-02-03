/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:14:45 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/03 11:41:38 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>


void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
long	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int	ft_strlen(const char *s);


#endif