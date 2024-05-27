/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/27 08:52:22 by wiljimen         ###   ########.fr       */
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
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			path_save = *env + 5;
			break ;
		}
		*env++;
	}
	path_complete = ft_split(path_save, ':');
	ft_protect(path_complete, "Free done in Path\n");
	while (path_complete[i])
	{
		path_complete[i] = ft_strjoin(path_complete[i], "/");
		i++;
	}
	return (path_complete);
}

char	**access_checker(char *argv, char **env, char **path)
{
	char	*temp;
	char	**temp2;
	char	**path_real;
	int		i;

	path_real = ft_calloc(array_len(path) + 1, sizeof(char *));
	temp2 = ft_calloc(array_len(path) + 1, sizeof(char *));
	i = 0;
	(ft_protect(path_real, "path_real"), ft_protect(temp2, "temp2"));
	while (*path)
	{
		temp = *path;
		*temp2 = ft_strjoin(temp, argv);
		(ft_protect_malloc(temp), ft_protect(temp2, "Temp2 free\n"));
		if ((access(*temp2, X_OK)) == 0)
		{
			path_real[i] = *temp2;
			i++;
		}
		free(temp);
		*temp2++;
		*path++;
	}
	free(*temp2);
	return (path_real);
}

// char	**comand_separator(char *argv, char **env)
// {
// 	char	**cmd;
// 	char	**path;
// 	char	**path_real;

// 	cmd = ft_split(argv, ' ');
// 	path = find_path(env);
// 	path_real = access_checker(cmd, env, path);
// 	int	i;

// 	i = 0;
// 	while (path_real[i])
// 	{
// 		printf("%s\n", path_real[i]);
// 		i++;
// 	}
// 	return (cmd);
// }

int	main(int argc, char **argv, char **env)
{
	char	**path;
	char	**path_real;
	
	if (argc != 2)
		print_error("More or less than 5 arguments");
	path = find_path(env);
	path_real = access_checker(argv[1], env, path);
	int	i = 0;
	while (path_real[i])
	{
		printf("%s\n", path_real[i]);
		i++;
	}
    return (0);
}
