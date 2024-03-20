/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endbsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:37 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 20:50:26 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_square(t_bsq *va)
{
	int	y;

	y = 0;
	while (y < va->n_lines)
	{
		write(1, va->bsq[y], va->n_columns);
		write(1, "\n", 1);
		y++;
	}
}

int	ft_opencheck(t_bsq *va, char *argv)
{
	if (!ft_openfile(va, argv))
	{
		close(va->fd);
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}

void	ft_endbsq(t_bsq *va)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	y = va->max_y;
	while (i < va->max_square)
	{
		j = 0;
		x = va->max_x;
		while (j < va->max_square)
		{
			va->bsq[y][x] = va->full;
			x++;
			j++;
		}
		y++;
		i++;
	}
	ft_print_square(va);
	ft_free_chars(va);
	free(va->bsq);
}
