/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 09:15:19 by aanger            #+#    #+#             */
/*   Updated: 2018/09/27 20:46:11 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len;
	char	*rslt;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(rslt = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = 0;
	while (*s1)
	{
		rslt[len] = *s1;
		s1++;
		len++;
	}
	while (*s2)
	{
		rslt[len] = *s2;
		len++;
		s2++;
	}
	rslt[len] = '\0';
	return (rslt);
}
