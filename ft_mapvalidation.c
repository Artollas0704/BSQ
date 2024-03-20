/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapvalidation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:35:01 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 15:29:47 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	rows_validation2(t_bsq *va, int i, int j, int c)
{
	int	lines;

	lines = 0;
	while (va->map[i])
	{
		if (va->map[i] == '\n' && lines < va->n_lines)
		{
			lines++;
			if (c == 0)
				c = i - j;
			if (c != i - j)
				return (0);
			if (lines == va->n_lines)
				break ;
			j = i + 1;
		}
		if (va->map[i])
			i++;
	}
	if (va->map[i + 1] != 0 || lines != va->n_lines)
		return (0);
	va->n_columns = c;
	va->vmap_size = i;
	return (1);
}

int	rows_validation(t_bsq *va)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = va->first_line;
	j = va->first_line;
	if (!rows_validation2(va, i, j, c))
	{
		return (0);
	}
	return (1);
}

int	character_validation(t_bsq *va)
{
	int	i;

	i = 0;
	if (va->full < 32 || va->full == 127 || va->empty < 32 
		|| va->empty == 127 || va->obstacle < 32 
		|| va->obstacle == 127)
		return (0);
	if (va->full == va->empty || va->full == va->obstacle 
		|| va->obstacle == va->empty)
		return (0);
	while (va->map[i] != '\n')
		i++;
	while (va->map[i] && i <= va->vmap_size)
	{
		if (va->map[i] != va->empty 
			&& va->map[i] != va->obstacle && va->map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	get_characters(t_bsq *va)
{
	int	i;

	i = 0;
	while (va->map[i] != '\n')
		i++;
	va->full = va->map[i - 1];
	va->obstacle = va->map[i - 2];
	va->empty = va->map[i - 3];
	if (va->map[i + 1] != va->obstacle 
		&& va->map[i + 1] != va->empty)
		return (0);
	i = i - 4;
	while (i >= 0)
	{
		if (!(va->map[i] >= '0' && va->map[i] <= '9'))
			return (0);
		i--;
	}
	return (1);
}

int	ft_mapvalidation(t_bsq *va)
{
	int	i;

	i = 0;
	while (va->map[i] != '\n' && va->map[i] != 0)
		i++;
	if (va->map[i] != '\n')
		return (0);
	va->first_line = i + 1;
	if (!get_characters(va))
		return (0);
	ft_atoi(va);
	if (va->n_lines == 0)
		return (0);
	if (!(rows_validation(va)))
		return (0);
	if (!character_validation(va))
		return (0);
	return (1);
}
