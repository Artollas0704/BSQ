/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:26:47 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 01:55:39 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_fillmap(t_bsq *va)
{
	int	y;
	int	x;

	y = va->n_lines - 1;
	while (y >= 0)
	{
		x = va->n_columns - 1;
		while (x >= 0)
		{
			if (va->bsq[y][x] == va->obstacle)
				va->bsq_ints[y][x] = 0;
			else
			{
				if (va->bsq_ints[y + 1][x] != 0 || va->bsq_ints[y][x + 1] != 0 || va->bsq_ints[y + 1][x + 1] != 0)
				{
					if (va->bsq_ints[y + 1][x] <= va->bsq_ints[y][x + 1] && va->bsq_ints[y + 1][x] <= va->bsq_ints[y + 1][x + 1])
					{
						va->bsq_ints[y][x] = va->bsq_ints[y + 1][x] + 1;
						
						if (va->bsq_ints[y][x] >= va->max_square)
						{
							va->max_x = x;
							va->max_y = y;
							va->max_square = va->bsq_ints[y + 1][x] + 1;
						}
					}
					else if (va->bsq_ints[y][x + 1] <= va->bsq_ints[y + 1][x] && va->bsq_ints[y][x + 1] <= va->bsq_ints[y + 1][x + 1])
					{
						va->bsq_ints[y][x] = va->bsq_ints[y][x + 1] + 1;
						if (va->bsq_ints[y][x] >= va->max_square)
						{
							va->max_x = x;
							va->max_y = y;
							va->max_square = va->bsq_ints[y][x + 1] + 1;
						}
					}
					else if (va->bsq_ints[y + 1][x + 1] <= va->bsq_ints[y + 1][x] && va->bsq_ints[y + 1][x + 1] <= va->bsq_ints[y][x + 1])
					{
						va->bsq_ints[y][x] = va->bsq_ints[y + 1][x + 1] + 1;
						if (va->bsq_ints[y][x] >= va->max_square)
						{
							va->max_x = x;
							va->max_y = y;
							va->max_square = va->bsq_ints[y + 1][x + 1] + 1;
						}
					}
				}
				else
				{
					va->bsq_ints[y][x] = 1;
					if (va->bsq_ints[y][x] >= va->max_square)
						{
							va->max_x = x;
							va->max_y = y;
							va->max_square = va->bsq_ints[y][x];
						}
				}
			}
			x--;
		}
		y--;
	}
	ft_free_ints(va);
	free(va->bsq_ints);
}

void	ft_firstfill(t_bsq *va)
{
	int	y;
	int	x;

	y = va->n_lines;
	while (y >= 0)
	{
		x = va->n_columns;
		while (x >= 0)
		{
			if (x == va->n_columns || y == va->n_lines)
				va->bsq_ints[y][x] = 0;
			x--;
		}
		y--;
	}
}

void	ft_copy_map(t_bsq *va)
{
	int	i;
	int	x;
	int	y;

	i = va->first_line;
	y = 0;
	while (y < va->n_lines)
	{
		x = 0;
		while (va->map[i] != '\n' && va->map[i] && x < va->n_columns)
		{
			
			va->bsq[y][x] = va->map[i];
			i++;
			x++;
		}
		 va->bsq[y][x] = '\0';
		if (va->map[i] && i < va->vmap_size)
			i++;
		y++;
	}
	free(va->map);
}

void	ft_bsq(t_bsq *va)
{
	int	i;

	i = 0;
	va->bsq = (char **)malloc((va->n_lines + 1) * sizeof(char *));
	if (!va->bsq)
		return ;
	va->bsq[va->n_lines] = 0;
	while (i < va->n_lines)
	{
		va->bsq[i] = (char *)malloc((va->n_columns + 1) * sizeof(char));
		if (!(va->bsq[i]))
			return ;
		i++;
	}
	ft_copy_map(va);
	ft_allocate(va);
	ft_firstfill(va);
	ft_fillmap(va);
	ft_endbsq(va);
}
