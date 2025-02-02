/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:52:12 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:17:46 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, lst_new(j));
		i++;
	}
	ft_free_str(tmp);
	free(tmp);
	return (a);
}
t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_add_back(&a, lst_new(j));
			i++;
		}
	}
	return (a);
}