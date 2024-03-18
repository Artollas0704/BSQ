/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:19:18 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:05 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 10000000000

typedef struct bsq
{
	char 	empty; // Empty character
	char 	obstacle; // Obstacle Character
	char 	full; // Full character
	char 	*map; // Read map from file
	int		size; // What read function returned
	int		fd; // File Descriptor of opening file
	int		first_line; // After the line of the map with informations
	int		n_lines; // Number of lines from the first line (ft_atoi)
	int		n_columns; // Number of columns
	int		vmap_size; // Valid size of the map (even if there is stuff after it)
} t_bsq;

#endif