/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aballest <aballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:17:51 by aballest          #+#    #+#             */
/*   Updated: 2019/11/26 20:09:04 by aballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strnew(size_t size)
{
	char       *str;
    size_t     i;

    i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
    while (i < size)
    	str[i++] = 0;
    str[size] = '\0';
	return (str);
}

void		ft_strdel(char **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

int		ft_new_line(char **str, char **line, int fd, int result)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (result == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[255];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			result;

	if (fd < 0 || !line)
		return (-1);
	while ((result = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[result] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (result < 0)
		return (-1);
	else if (result == 0 && (!str[fd] || str[fd][0] == '\0'))
		return (0);
	return (ft_new_line(str, line, fd, result));
}
