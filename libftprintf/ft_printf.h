/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:41:24 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/19 18:18:57 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *, ...);
void	ft_putchar_printf(char c, size_t *count);
void	ft_putstr_printf(char *str, size_t *count);
void	ft_putnbr_printf(int nbr, size_t *count);
void	ft_unsigned_printf(unsigned int n, size_t *count);
void	ft_putaddress_printf(unsigned long n, size_t *count);
void	ft_puthexa_printf(unsigned int n,  size_t *count, const char *c);

#endif
