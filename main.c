/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:52:45 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 20:50:16 by aralves-         ###   ########.fr       */
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
	va->map = (char *)malloc(sizeof(char));
	if (!(va->map))
		return (0);
	va->map[0] = '\0';
	while ((va->size > 0))
	{
		ft_realloc(va);
		va->size = read(0, va->str, va->buffer_size);
		va->str[va->size] = '\0';
		va->map = ft_strcat(va->map, va->str);
	}
	if (!ft_mapvalidation(va))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	free(va->str);
	return (1);
}

int	ft_checks(t_bsq *va, char *argv)
{
	va->map = (char *)malloc(sizeof(char));
	if (!va->map)
		return (0);
	va->map[0] = '\0';
	if (ft_opencheck(va, argv))
	{
		while ((va->size > 0))
		{
			ft_realloc(va);
			va->size = read(va->fd, va->str, va->buffer_size);
			va->str[va->size] = '\0';
			va->map = ft_strcat(va->map, va->str);
		}
		if (!ft_mapvalidation(va))
		{
			free(va->str);
			free(va->map);
			write(2, "map error\n", 10);
			return (0);
		}
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
	va->y = 0;
	va->x = 0;
	va->buffer_size = 50;
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
			ft_newline(argc, i++);
		}
	}
	else
	{
		init_structure(va);
		if (ft_stdi(va))
			ft_bsq(va);
	}
	free(va);
	return (0);
}
