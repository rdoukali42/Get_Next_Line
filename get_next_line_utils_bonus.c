/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:38:10 by rdoukali          #+#    #+#             */
/*   Updated: 2022/04/27 05:19:03 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check(char *str, int c)
{
	int		i;
	char	uc;

	i = 0;
	uc = (char)c;
	if (!str)
		return (0);
	if (!c)
		return (0);
	while (str[i])
	{
		if (str[i] == uc)
			return (1);
		i++;
	}
	return (0);
}

char	*add(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
