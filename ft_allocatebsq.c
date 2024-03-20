/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocatebsq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:34:46 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 17:08:13 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_realloc(t_bsq *va)
{
	if (va->size != 0 && va->size == va->buffer_size)
		va->buffer_size *= 2;
	free(va->str);
	va->str = (char *)malloc(va->buffer_size + 1 * sizeof(char));
}

void	ft_allocate(t_bsq *va)
{
	int	i;

	i = 0;
	va->bsq_ints = (int **)malloc((va->n_lines + 1) * sizeof(int *));
	if (!(va->bsq_ints))
		return ;
	while (i <= va->n_lines)
	{
		va->bsq_ints[i] = (int *)malloc((va->n_columns + 1) * sizeof(int));
		if (!va->bsq_ints[i])
			return ;
		i++;
	}
}
