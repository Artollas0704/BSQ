/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:52:45 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 03:44:04 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_openfile(t_bsq *va, char *argv)
{
	va->fd = open(argv, O_RDONLY);
	if (va->fd < 0)
	{
		close (va->fd);
		return (0);
	}
	return (1);
}

int	ft_stdi(t_bsq *va)
{
	va->str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	va->map = (char *)malloc(sizeof(char));
	va->map[0] = '\0';
	while (va->size > 0)
	{
		va->size = read(0, va->str, BUFFER_SIZE);
		va->str[va->size] = '\0';
		va->map = ft_strcat(va->map, va->str);
	}
	if (!ft_mapvalidation(va))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}

int	ft_checks(t_bsq *va, char *argv)
{
	va->str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	va->map = (char *)malloc(sizeof(char));
	va->map[0] = '\0';
	if (!ft_openfile(va, argv))
	{
		close(va->fd);
		write(2, "Error opening the file\n", 23);
		return (0);
	}
	while ((va->size > 0))
	{
		va->size = read(va->fd, va->str, BUFFER_SIZE);
		va->str[va->size] = '\0';
		va->map = ft_strcat(va->map, va->str);
	}
	if (!ft_mapvalidation(va))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	close(va->fd);
	free(va->str);
	return (1);
}

void	init_structure(t_bsq *va)
{
	va->empty = 0;
	va->fd = 0;
	va->obstacle = 0;
	va->first_line = 0;
	va->full = 0;
	va->map = 0;
	va->n_columns = 0;
	va->n_lines = 0;
	va->size = 1;
	va->vmap_size = 0;
	va->str = 0;
	va->bsq = 0;
	va->bsq_ints = 0;
	va->max_square = 0;
	va->max_x = 0;
	va->max_y = 0;
}

int	main(int argc, char **argv)
{
	int		i;
	t_bsq	*va;

	i = 1;
	va = malloc(sizeof(t_bsq));
	if (!va)
		return (0);
	if (argc > 1)
	{
		while (i <= argc - 1)
		{
			init_structure(va);
			if (ft_checks(va, argv[i]))
				ft_bsq(va);
			i++;
		}
	}
	else
	{
		init_structure(va);
		if(ft_stdi(va))
			ft_bsq(va);
	}
	free(va);
	return (0);
}
