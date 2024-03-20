/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:31:18 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 15:27:56 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_chars(t_bsq *va)
{
	int	i;

	i = 0;
	while (i < va->n_lines)
	{
		free(va->bsq[i]);
		i++;
	}
}

void	ft_free_ints(t_bsq *va)
{
	int	i;

	i = 0;
	while (i <= va->n_lines)
	{
		free(va->bsq_ints[i]);
		i++;
	}
}
