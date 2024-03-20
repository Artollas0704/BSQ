/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:19:18 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/20 17:08:36 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct bsq
{
	char			empty;
	char			obstacle;
	char			full;
	char			*map;
	unsigned int	size;
	int				fd;
	int				first_line;
	int				n_lines;
	int				n_columns;
	int				vmap_size;
	char			*str;
	char			**bsq;
	int				max_x;
	int				max_y;
	int				max_square;
	int				**bsq_ints;
	int				x;
	int				y;
	unsigned int	buffer_size;
}	t_bsq;

void	ft_newline(int argc, int i);
int		ft_checks(t_bsq *va, char *argv);
void	ft_mapinfo(t_bsq *va);
int		ft_mapvalidation(t_bsq *va);
char	*ft_strcat(char *dest, char *src);
void	ft_put0(char *str);
void	ft_atoi(t_bsq *va);
int		ft_strlen(char *str);
void	ft_bsq(t_bsq *va);
void	ft_allocate(t_bsq *va);
void	ft_endbsq(t_bsq *va);
void	ft_free_ints(t_bsq *va);
void	ft_free_chars(t_bsq *va);
int		check_diagonal(t_bsq *va);
int		check_bottom(t_bsq *va);
int		check_right(t_bsq *va);
void	equal_zero(t_bsq *va);
int		diff_zero(t_bsq *va);
void	ft_realloc(t_bsq *va);

#endif

/* typedef struct bsq
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
	char	*str;
}	t_bsq; */