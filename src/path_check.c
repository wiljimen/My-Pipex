/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:35 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/28 17:35:06 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**find_path(char **env)
{
	char	*path_save;
	char	**path_complete;
	int		i;

	path_save = NULL;
	path_complete = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path_save = env[i] + 5;
			break ;
		}
		i++;
	}
	path_complete = ft_split(path_save, ':');
	ft_protect(path_complete, "Free done in Path\n");
	i = 0;
	while (path_complete[i])
	{
		path_complete[i] = ft_strjoin(path_complete[i], "/");
		i++;
	}
	return (path_complete);
}

void	ft_free_two(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_free(char **temp, char *str)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	ft_protect(char **temp, char *str)
{
	if (!temp)
		ft_free(temp, str);
}

int	array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
