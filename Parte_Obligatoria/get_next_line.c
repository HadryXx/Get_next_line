/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aballest <aballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:17:51 by aballest          #+#    #+#             */
/*   Updated: 2019/12/19 15:25:58 by aballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_end_chr(const char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int			ft_print_line(char **s, char **line)
{
	int		end_chr;
	char	*tmp;

	end_chr = get_end_chr(*s);
	if ((*s)[end_chr] == '\n')
	{
		*line = ft_substr(*s, 0, end_chr);
		tmp = ft_substr(*s, end_chr + 1, ft_strlen(*s));
		free(*s);
		*s = tmp;
		return (1);
	}
	else
	{
		*line = ft_substr(*s, 0, ft_strlen(*s));
		ft_strdel(s);
		return (0);
	}
}

int			ft_read_line(char **s, int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		result;

	while ((result = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[result] = '\0';
		if (!s[fd])
			s[fd] = ft_substr("", 0, 0);
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			return (ft_print_line(&s[fd], line));
	}
	if (result < 0)
		return (-1);
	else if (result == 0 && !s[fd])
	{
		*line = ft_substr("", 0, 0);
		return (0);
	}
	else
		return (ft_print_line(&s[fd], line));
}

int			get_next_line(int fd, char **line)
{
	static char		*str[4096];

	if (fd < 0 || !line)
		return (-1);
	if (str[fd] && ft_strchr(str[fd], '\n'))
		return (ft_print_line(&str[fd], line));
	else
		return (ft_read_line(str, fd, line));
}
