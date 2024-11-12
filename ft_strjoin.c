/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:59:30 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/06 20:48:14 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)//this function combines two strings s1,s2 and 
												// into a new string , it allocate enough memory
												// to hold both strings and then it copies one after the other 
												//into a new space
{
	char	*newstr;
	size_t	maxlen;

	if (!s1)
		s1 = "";// if s1 or s2 is null we set them to empty string , this avoid errors when trying to calculate the len of str
	if (!s2)
		s2 = "";
	maxlen = (ft_strlen(s1) + ft_strlen(s2) + 1);// we calculate the leng of the new str
	newstr = (char *)malloc(maxlen);// we allocat memory for it
	if (newstr == NULL) //if malloc fails return null
		return (NULL);
	ft_memcpy(newstr, s1, ft_strlen(s1)); // cpy the content of s1 into the new str
	ft_memcpy(&newstr[ft_strlen(s1)], s2, ft_strlen(s2));// cpy into the pos &newstr[fy_strlen(s1)] mneaing the end of the first str
	newstr[maxlen - 1] = '\0';// we set '\0' to the last byte in the new str
	return (newstr);
}
/*#include<stdio.h>
int main()
{
char	*s1 = "hello";
char	*s2 = "";
printf("The joined str using ft_strjoin is : %s\n" ,ft_strjoin(s1, s2));
}*/