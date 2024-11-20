/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:20 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/20 10:11:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress_printf(unsigned long n, size_t *count)
{
	*count += write(1, "0x", 2);
	ft_puthexa_printf(n, count, "0123456789abcdef");
}
