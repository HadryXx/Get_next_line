/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aballest <aballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 03:12:33 by aballest          #+#    #+#             */
/*   Updated: 2019/11/26 17:36:37 by aballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

char		*ft_strdup(const char *src)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	if ((newstr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	a = 0;
	if (!(start > ft_strlen((char *)s)))
	{
		while (a < len && s[start + a])
		{
			newstr[a] = s[start + a];
			a++;
		}
	}
	newstr[a] = '\0';
	return (newstr);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	x;
	char			*newstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if ((newstr = (char*)malloc(sizeof(char) * (x + 1))) == NULL)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		newstr[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b])
	{
		newstr[a] = s2[b];
		a++;
		b++;
	}
	newstr[a] = '\0';
	return (newstr);
}
