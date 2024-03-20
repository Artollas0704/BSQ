/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endbsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:37 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 15:28:55 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
	i = 0;
	while (i < va->n_lines)
	{
		printf("%s\n", va->bsq[i]);
		i++;
	}
	ft_free_chars(va);
	free(va->bsq);
}
