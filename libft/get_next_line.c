/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:32:39 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/18 17:17:01 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_auxwrite(int fd, char *aux)
{
	char	*line;
	int		read_bytes;
	char	*save;

	read_bytes = 1;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (!aux || (!ft_strchr(aux, '\n') && read_bytes != 0))
	{
		read_bytes = read(fd, line, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(line);
			free(aux);
			return (NULL);
		}
		line[read_bytes] = '\0';
		save = aux;
		aux = ft_strjoin_aux(aux, line);
		free(save);
	}
	free(line);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	aux = ft_auxwrite(fd, aux);
	if (!aux || !aux[0])
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	result = ft_strcprinter(&aux);
	return (result);
}

char	*ft_strcprinter(char **s)
{
	char	*retstr;
	char	*aux;
	int		i;

	i = 0;
	aux = *s;
	while (*s && (*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s) && (*s)[i] == '\n')
		i++;
	retstr = ft_substr(*s, 0, i);
	*s = ft_substr(*s, i, ft_strlen_aux((const char *)*s));
	if (!*s)
		free(*s);
	free(aux);
	if (!retstr[0])
	{
		free(retstr);
		retstr = NULL;
	}
	return (retstr);
}
