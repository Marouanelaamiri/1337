/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:55:46 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/12 13:59:56 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*ret;

	ch = (char) c;
	i = 0;
	ret = NULL;
	while (s[i])
	{
		if (s[i] == ch)
			ret = (char *) &s[i];
		i++;
	}
	if (ch == '\0')
		return ((char *) &s[i]);
	else
		return (ret);
}
