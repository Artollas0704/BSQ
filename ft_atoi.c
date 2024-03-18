/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:15:35 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/18 22:00:18 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_atoi(t_bsq *values)
{
	int	i;

	i = 0;
	while ((values->map[i] >= '0' && values->map[i] <= '9') && i < (values->first_line - 4))
	{
		values->n_lines =  values->n_lines * 10 + values->map[i] - 48;
		i++;
	}
}
