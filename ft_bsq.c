/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:23:48 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/03/20 17:07:22 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_newline(int argc, int i)
{
	if (i < argc - 1)
		write(1, "\n", 1);
}

void	ft_fillmap(t_bsq *va)
{
	va->y = va->n_lines - 1;
	while (va->y >= 0)
	{
		va->x = va->n_columns - 1;
		while (va->x >= 0)
		{
			if (va->bsq[va->y][va->x] == va->obstacle)
				va->bsq_ints[va->y][va->x] = 0;
			else
			{
				if (diff_zero(va) == 0)
					equal_zero(va);
			}
			va->x--;
		}
		va->y--;
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
