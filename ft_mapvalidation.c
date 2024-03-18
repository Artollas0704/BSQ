/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapvalidation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:35:01 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/18 23:04:14 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(t_bsq *values);
int	ft_strlen(char *str);

int	rows_validation(t_bsq *values)
{
	int	i;
	int	j;
	int c;
	int	lines;

	lines = 0;
	ft_atoi(values);
	if (values->n_lines == 0)
		return (0);
	c = 0;
	i = values->first_line;
	j = values->first_line;
	while (values->map[i])
	{
		if(values->map[i] == '\n' && lines < values->n_lines)
		{
			lines++;
			if(c == 0)
				c = i - j;
			if (c != i - j)
				return (0);
			if (lines == values->n_lines)
				break;
			j = i + 1;
		}
		if(values->map[i])
			i++;
	}
	if (values->map[i + 1] != 0 || lines != values->n_lines)
		return (0);
	values->vmap_size = i;
	return(1);
}

int	character_validation(t_bsq *values)
{
	int	i;

	i = 0;
	if (values->full < 32 || values->full == 127 || values->empty < 32 
		|| values->empty == 127 || values->obstacle < 32 
		|| values->obstacle == 127)
		return (0);
	if (values->full == values->empty || values->full == values->obstacle 
		|| values->obstacle == values->empty)
		return (0);
	while (values->map[i] != '\n')
		i++;
	while (values->map[i] && i <= values->vmap_size)
	{
		if (values->map[i] != values->empty 
			&& values->map[i] != values->obstacle && values->map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
int		get_characters(t_bsq *values)
{
	int	i;

	i = 0;
	while(values->map[i] != '\n')
		i++;
	values->full = values->map[i - 1];
	values->obstacle = values->map[i - 2];
	values->empty = values->map[i - 3];
	if (values->map[i + 1] != values->obstacle && values->map[i + 1] != values->empty)
		return (0);
	i = i - 4;
	while(i >= 0)
	{
		if (!(values->map[i] >= '0' && values->map[i] <= '9'))
			return (0);
		i--;
	}
	return (1);
}
int	ft_mapvalidation(t_bsq *values)
{
	int	i;

	i = 0;
	while (values->map[i] != '\n' && values->map[i] != 0)
		i++;
	if (values->map[i] != '\n')
		return (0);
	values->first_line = i + 1;
	if (!get_characters(values))
		return (0);
	if (!(rows_validation(values)))
		return (0);
	if (!character_validation(values))
		return (0);
	return (1);
}
