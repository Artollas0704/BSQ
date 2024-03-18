/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:52:45 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/18 21:48:26 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_mapinfo(t_bsq *values);
int	ft_mapvalidation(t_bsq *values);

void	init_structure(t_bsq *values)
{
	values->empty = 0;
	values->fd = 0;
	values->obstacle = 0;
	values->first_line = 0;
	values->full = 0;
	values->map = 0;
	values->n_columns = 0;
	values->n_lines = 0;
	values->size = 0;
	values->vmap_size = 0;
} 
int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_bsq	*values;
	i = 1;
	fd = 0;
	values = malloc(sizeof(t_bsq));
	if (!values)
		return (0);
	init_structure(values);
	if (argc > 1)
	{
		while (i <= argc - 1)
		{
			values->map = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
			if(!(values->fd = open(argv[i], O_RDONLY)))
			{
				close (values->fd);
				write(2, "Error opening the file\n",23);
				exit (0);
			}
			else if(!(values->size = read(values->fd, values->map, BUFFER_SIZE)))
			{
				write(2, "map error\n", 10);
			}
			else 
			{
				if(!ft_mapvalidation(values))
					write(2, "map error\n", 10);
			}
			//printf("%s", values->map);
			i++;
		}
		close(values->fd);
	}
	free(values->map);
	free(values);
	return (0);
}
