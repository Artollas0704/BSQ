/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:52:45 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/18 11:47:49 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_mapinfo(char *buf, int file_len);
int	ft_mapvalidation(char *buf, int file_len);

int	main(int argc, char **argv)
{
	char	buf[100000];
	int		fd;
	int		file_len;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i <= argc - 1)
		{
			fd = open(argv[i], O_RDONLY);
			file_len = read(fd, buf, 100000);
			if (ft_mapvalidation(buf, file_len) == 0)
				write(1, "map error\n", 10);
			else 
				ft_mapinfo(buf, file_len);
			i++;
		}
		printf("%s", buf);
	}
}
