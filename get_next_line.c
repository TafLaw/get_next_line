/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:27:39 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/06/21 11:09:24 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				count;
	char			buff[BUFF_SIZE + 1];
	static char			*str;

	str = "";
	i = 0;
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[BUFF_SIZE] = '\0';
		str = ft_strjoin(str, buff);
	/*	while (str[i] != '\0')
		{
			if (str[i] == '\n')
			{
				str[i] = '\0';
				*line = ft_strdup(str);
				return (1);
			}
			i++;
		}*/
		*line = ft_strdup(str);
		if (ft_strchr(buff, '\n'))
			return (1);
	}
	//buff[count] = '\0';
	//*line = ft_strdup("THE END!");
	return (1);
}
