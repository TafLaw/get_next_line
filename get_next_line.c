/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:27:39 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/06/25 17:13:21 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		step(char **line, char *str, unsigned int size)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = ft_strdup(str);
	while (str[i] != '\0' && i < size)
	{
		if (str[i] == '\n') 
			break ;
		i++;
	}
	*line = ft_strsub(temp, 0, i);
	ft_strdel(&temp);
	if (ft_strlen(*line) == 0)
		return (0);
	free(*line);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	//int				count;
	char			buff[BUFF_SIZE + 1];
	static char		*str;
	
	str = "";
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	/*if (fd == 0)
		return (0);*/
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[BUFF_SIZE] = '\0';
		str = ft_strjoin(str, buff);
		free(str);
		if (ft_strchr(buff, '\n'))
			break ;
		ft_strclr(buff);
	}
	return (step(line, str, ft_strlen(str)));
}
