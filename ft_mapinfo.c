/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:15:35 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/17 16:29:44 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

void	ft_get_characters(char *buf, char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
	{
		i++;
	}
	str[0] = buf[i];
	str[1] = buf[i + 1];
	str[2] = buf[i + 2];
	str[3] = '\0';
}

int	get_columns(char *buf, int len)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] != '\n')
	{
		i++;
	}
	i++;
	j = 0;
	while (buf[i] != '\n')
	{
		j++;
		i++;
	}
	return (j);
}

void	ft_mapinfo(char *buf, int file_len)
{
	char	*characters;
	int		ncolumns;
	int		lines;

	characters = (char *)malloc(4 * sizeof(char));
	ft_get_characters(buf, characters);
	ncolumns = get_columns(buf, file_len);
	lines = ft_atoi(buf);
}
