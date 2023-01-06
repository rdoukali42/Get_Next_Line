/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:37:55 by rdoukali          #+#    #+#             */
/*   Updated: 2022/04/27 05:18:21 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fil_buf(int fd, char *str)
{
	int		nb;
	char	*buf;

	nb = 2;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while ((!(check(str, '\n')) && nb != 0))
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nb] = '\0';
		if (!str)
		{
			str = (char *)malloc(sizeof(char) * 1);
			str[0] = '\0';
		}
		str = add(str, buf);
	}
	free(buf);
	return (str);
}

char	*fil_to_nl(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i - 1] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (buf[j - 1] != '\n')
	{
		str[j] = buf[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*fil_all(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!buf[i])
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	while (buf[i])
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*buff_rest(char	*buf)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (buf[i] != '\n')
		i++;
	ptr = malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!ptr)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
	{
		ptr[j] = buf[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	free(buf);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*ptr;
	static char	*buffer[256];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (0);
	buffer[fd] = fil_buf(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (check(buffer[fd], '\n'))
		ptr = fil_to_nl(buffer[fd]);
	else
		ptr = fil_all(buffer[fd]);
	if (!check(buffer[fd], '\n'))
	{
		free(buffer[fd]);
		buffer[fd] = NULL ;
	}
	else
		buffer[fd] = buff_rest(buffer[fd]);
	return (ptr);
}
