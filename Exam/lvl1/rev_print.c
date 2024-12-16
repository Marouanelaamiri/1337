/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:39:30 by malaamir          #+#    #+#             */
/*   Updated: 2024/12/16 14:41:40 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *rev_print(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		write(1, &str[i--], 1);
	write(1, "\n", 1);
	return (str);
}
int main(void)
{
  rev_print("Hello world");
//   write (1, "\n", 1);
  rev_print("tnirp esreveR");
//   write (1, "\n", 1);
  rev_print("");
//   write (1, "\n", 1);
}