/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:15:35 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/18 10:50:46 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	a;

	i = 0;
	num = 0;
	a = 0;
	while (str[a] != '\n')
		a++;
	while ((str[i] >= '0' && str[i] <= '9') && i < (a - 3))
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
	while (buf[i] != '\n')
		i++;
	str[0] = buf[i - 1];
	str[1] = buf[i - 2];
	str[2] = buf[i - 3];
	str[3] = '\0';
}

int	get_columns(char *buf, int len)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] != '\n')
		i++;
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
