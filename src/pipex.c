/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/27 19:55:40 by wiljimen         ###   ########.fr       */
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

char	**access_checker(char *argv, char **env)
{
	char	*temp;
	char	**path;
	char	**path_real;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path = find_path(env);
	path_real = ft_calloc(array_len(path) + 1, sizeof(char *));
	ft_protect(path_real, "path_real");
	while (path[j])
	{
		temp = path[j];
		temp = ft_strjoin(temp, argv);
		if ((access(temp, X_OK)) == 0 || access(temp, F_OK) == 0)
		{
			path_real[i] = ft_strdup(temp);
			i++;
		}
		free(temp);
		j++;
	}
	free(path);
	i = 0;
	while (path_real[i])
	{
		printf("%s\n", path_real[i]);
		i++;
	}
	return (path_real);
}

char	**command_separator(char *argv, char **env)
{
	char	**cmd;
	char	**path_real;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path_real = access_checker(cmd[0], env);
	if (!path_real[i])
	{
		printf("zsh: command not found: %s\n", cmd[0]);
		ft_free(path_real, "");
	}

	return (cmd);
}

// void	father_process(char **path_real, char *argv, char **env, char **cmd)
// {
// 	int		fd[2];
// 	int		fd1;
// 	int		pid;
// 	int		i;
	
// 	pid = fork();
// 	i = 0;
// 	pipe(fd);
// 	if (pid == 0)
// 	{
// 		close(fd[READ_END]);
// 		dup2(fd[WRITE_END], STDOUT_FILENO);
// 		close(fd[WRITE_END]);
// 		execve(path_real[i], ,env);
// 	}

// }

int	main(int argc, char **argv, char **env)
{
	if (argc != 2)
		print_error("More or less than 5 arguments");
	command_separator(argv[1], env);
	system("leaks -q pipex");
    return (0);
}
