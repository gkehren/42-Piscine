/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:27:44 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/20 10:40:39 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_count_line(char *file, int *size)
{
	char	buffer[BUF + 1];
	int		fd;
	int		i;
	int		count;
	int		ret;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buffer, BUF);
	while (ret)
	{
		i = -1;
		buffer[ret] = 0;
		*size += ret;
		while (buffer[++i])
			if (buffer[i] == '\n')
				count ++;
		ret = read(fd, buffer, BUF);
	}
	close(fd);
	return (count);
}

void	write_file_in_tab(char *file, int nb_char, char **all_file)
{
	char	buffer[BUF + 1];
	int		fd;
	int		i;
	int		count;
	int		ret;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	(*all_file)[nb_char] = 0;
	ret = read(fd, buffer, BUF);
	while (ret)
	{
		i = 0;
		buffer[ret] = 0;
		while (buffer[i])
		{
			(*all_file)[count] = buffer[i];
			count ++;
			i++;
		}
		ret = read(fd, buffer, BUF);
	}
	close(fd);
}
