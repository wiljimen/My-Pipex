/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:32 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	i = 0;
	if ((access(argv, X_OK)) == 0)
	{
		path_real[i] = ft_strdup(argv);
	}
	if (!path_real[i])
	{
		ft_printf("Command not found: %s\n", cmd[0]);
		ft_free(path_real, "");
	}
	ft_free_two(path_real);
	return (cmd);
}

void	son_process(int *fd, char **argv, char **env)
{
	int		fd_infile;
	char	**path_real;
	char	**cmd;

	cmd = command_separator(argv[2], env);
	path_real = access_checker(cmd[0], env);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
	{
		ft_printf("Bad infile\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(fd_infile, STDIN_FILENO);
	close(fd[READ_END]);
	if ((access(cmd[0], X_OK)) == 0)
		execve(cmd[0], cmd, NULL);
	else
		execve(path_real[0], cmd, NULL);
	ft_free_two(path_real);
	ft_free_two(cmd);
}

void	father_process(int *fd, char **argv, char **env)
{
	int		fd_outfile;
	char	**path_real;
	char	**cmd;

	cmd = command_separator(argv[3], env);
	path_real = access_checker(cmd[0], env);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		ft_printf("Bad outfile\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd[WRITE_END]);
	if ((access(cmd[0], X_OK)) == 0)
		execve(cmd[0], cmd, NULL);
	else
		execve(path_real[0], cmd, NULL);
	ft_free_two(path_real);
	ft_free_two(cmd);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid;		
	int	status;

	if (argc != 5)
	{
		ft_printf("More or less than 5 arguments\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		ft_printf("Bad pipe\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		son_process(fd, argv, env);
	father_process(fd, argv, env);
	waitpid(pid, &status, 0);
	system("leaks -q pipex");
	return (0);
}
