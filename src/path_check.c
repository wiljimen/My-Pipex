/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:35 by wiljimen          #+#    #+#             */
/*   Updated: 2024/08/22 17:33:49 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			if (env[i][5] != '\0')
				return (env[i] + 5);
			else
				return (NULL);
		}
		i++;
	}
	exit_value(EXIT_FAILURE, "Error");
	return (NULL);
}

char	**find_path(char **env)
{
	char	*path_save;
	char	**path_complete;
	int		i;

	i = 0;
	path_save = get_path(env);
	path_complete = ft_split(path_save, ':');
	ft_protect(path_complete, "Free done in Path\n");
	while (path_complete[i])
	{
		if (access(path_complete[i], X_OK) == 0)
			path_complete[i] = ft_strjoin(path_complete[i], "/");
		i++;
	}
	return (path_complete);
}

int	array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
