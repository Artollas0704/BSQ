/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapvalidation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:35:01 by aralves-          #+#    #+#             */
/*   Updated: 2024/03/17 20:19:23 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_on_base(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && i < 2)
	{
		if (str[i] == c || c == '\n')
			return (1);
		i++;
	}
	return (0);
}
int	rows_validation(char *buf, int file_len, char *characters)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	if (buf[file_len - 1] != '\n')
		return (0);
	while (buf[i] != '\n')
		i++;
	i++;
	if (buf[i] == '\0')
		return(0);
	j = i;
	c = 0;
	while (buf[i] != '\n' && i < file_len)
	{
		i++;
		if (buf[i] == '\n')
		{
			if (c == 0)
				c = i - j;
			if (c != i - j)
				return(0);
			i++;
			j = i;
		}
	}
	if (buf[i] != '\0')
		return (0);
	return(1);
}

int	character_validation(char *characters, char *buf)
{
	int	i;
	int j;

	i = 0;
	while(characters[i])
	{
		j = i + 1;
		if (characters[i] < 32 || characters[i] == 127)
			return (0);
		while (characters[j])
		{
			if (characters[j] == characters[i])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	while (buf[i])
	{
		if(!(check_on_base(characters, buf[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_mapvalidation(char *buf, int file_len)
{
	int 	first_line;
	char	*characters;

	characters = (char *)malloc(4 *sizeof(char));
	first_line = 0;
	while(buf[first_line] != '\n')
		first_line++;
	characters[2] = buf[first_line - 1];
	characters[1] = buf[first_line - 2];
	characters[0] = buf[first_line - 3];
	if (!character_validation(characters, buf))
		return (0);
	first_line -= 4;
	while(first_line >= 0)
	{
		if (!(buf[first_line] >= '0' && buf[first_line] <= '9'))
			return (0);
		first_line--;
	}
	if (!(rows_validation(buf, file_len, characters)))
		return (0);
	return (1);
}
