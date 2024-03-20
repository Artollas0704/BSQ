/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:24:51 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/03/20 15:26:25 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_right(t_bsq *va)
{
	if (va->bsq_ints[va->y][va->x + 1] <= va->bsq_ints[va->y + 1][va->x]
		&& va->bsq_ints[va->y][va->x + 1] <= va->bsq_ints[va->y + 1][va->x + 1])
	{
		va->bsq_ints[va->y][va->x] = va->bsq_ints[va->y][va->x + 1] + 1;
		if (va->bsq_ints[va->y][va->x] >= va->max_square)
		{
			va->max_x = va->x;
			va->max_y = va->y;
			va->max_square = va->bsq_ints[va->y][va->x + 1] + 1;
		}
		return (1);
	}
	return (0);
}

int	check_bottom(t_bsq *va)
{
	if (va->bsq_ints[va->y + 1][va->x] <= va->bsq_ints[va->y][va->x + 1]
		&& va->bsq_ints[va->y + 1][va->x] <= va->bsq_ints[va->y + 1][va->x + 1])
	{
		va->bsq_ints[va->y][va->x] = va->bsq_ints[va->y + 1][va->x] + 1;
		if (va->bsq_ints[va->y][va->x] >= va->max_square)
		{
			va->max_x = va->x;
			va->max_y = va->y;
			va->max_square = va->bsq_ints[va->y + 1][va->x] + 1;
		}
		return (1);
	}
	return (0);
}

int	check_diagonal(t_bsq *va)
{
	if (va->bsq_ints[va->y + 1][va->x + 1] <= va->bsq_ints[va->y + 1][va->x]
		&& va->bsq_ints[va->y + 1][va->x + 1] <= va->bsq_ints[va->y][va->x + 1])
	{
		va->bsq_ints[va->y][va->x] = va->bsq_ints[va->y + 1][va->x + 1] + 1;
		if (va->bsq_ints[va->y][va->x] >= va->max_square)
		{
			va->max_x = va->x;
			va->max_y = va->y;
			va->max_square = va->bsq_ints[va->y + 1][va->x + 1] + 1;
		}
		return (1);
	}
	return (0);
}

void	equal_zero(t_bsq *va)
{
	va->bsq_ints[va->y][va->x] = 1;
	if (va->bsq_ints[va->y][va->x] >= va->max_square)
	{
		va->max_x = va->x;
		va->max_y = va->y;
		va->max_square = va->bsq_ints[va->y][va->x];
	}
}

int	diff_zero(t_bsq *va)
{
	if (va->bsq_ints[va->y + 1][va->x] != 0 
		|| va->bsq_ints[va->y][va->x + 1] != 0 
		|| va->bsq_ints[va->y + 1][va->x + 1] != 0)
	{
		if (check_bottom(va) == 0)
			if (check_right(va) == 0)
				if (check_diagonal(va) == 1)
					;
		return (1);
	}
	else
		return (0);
}
