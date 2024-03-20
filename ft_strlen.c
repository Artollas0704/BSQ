/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:47:03 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 03:26:33 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int				i;
	char			*line;
	int				j;

	j = 0;
	i = 0;
	line = (char *)malloc((ft_strlen(dest) + ft_strlen(src)) + 1);
	if (!line)
		return (0);
	while (dest[i] != '\0')
	{
		line[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		line[i++] = src[j++];
	}
	line[i] = 0;
	free (dest);
	return (line);
}
