/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed.mansour <ahmed.mansour@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 10:52:45 by ahmed.mansour     #+#    #+#             */
/*   Updated: 2025/07/19 13:38:21 by ahmed.mansour    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_nbr(int file)
{
	int		i;
	char	buffer[1];
	char	*str;

	str = (char *) malloc(sizeof(char) * 128);
	if (str == NULL)
		return (NULL);
	read(file, buffer, 1);
	while (buffer[0] == '\n')
		read(file, buffer, 1);
	i = 0;
	while (buffer[0] >= '0' && buffer[0] <= '9')
	{
		str[i] = buffer[0];
		read(file, buffer, 1);
		i++;
	}
	return (str);
}

char	*get_number_name(int file, char *buffer)
{
	int		i;
	char	*str;

	str = (char *) malloc(sizeof(char) * 128);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (buffer[0] != '\n')
	{
		str[i] = buffer[0];
		read(file, buffer, 1);
		i++;
	}
	return (str);
}

t_list	*create_list(char *file_name)
{
	int		i;
	int		file;
	char	buffer[1];
	t_list	*list;
	char	*tmp;

	file = open(file_name, O_RDONLY);
	list = (t_list *)malloc(sizeof(t_list) * 33);
	if (file == -1 || list == NULL)
		return (NULL);
	i = 0;
	while (i < 32)
	{
		list[i].nbr = ft_atoi(get_nbr(file));
		read(file, buffer, 1);
		while (buffer[0] == ' ')
			read(file, buffer, 1);
		if (buffer[0] == ':')
			read(file, buffer, 1);
		while (buffer[0] == ' ')
			read(file, buffer, 1);
		tmp = get_number_name(file, buffer);
		list[i].number_name = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	close(file);
	return (list);
}
