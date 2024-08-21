/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/08/21 17:41:57 by wiljimen         ###   ########.fr       */
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
		if ((access(temp, X_OK)) == 0 && access(temp, F_OK) == 0)
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
		path_real[i] = ft_strdup(argv);
	ft_free_two(path_real);
	return (cmd);
}

void	first_son_process(int *fd, char **argv, char **env)
{
	int		fd_infile;
	char	**path_real;
	char	**cmd;

	cmd = command_separator(argv[2], env);
	path_real = access_checker(cmd[0], env);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		print_error("Bad infile\n");
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(fd_infile, STDIN_FILENO);
	close(fd[READ_END]);
	if ((access(cmd[0], X_OK)) == 0)
		execve(path_real[0], path_real, NULL);
	else
		execve(path_real[0], cmd, NULL);
	perror("Error");
}

void	second_son_process(int *fd, char **argv, char **env)
{
	int			fd_outfile;
	char		**path_real;
	char		**cmd;

	cmd = command_separator(argv[3], env);
	path_real = access_checker(cmd[0], env);
	if (access(path_real[0], F_OK != 0))
	{
		code_error("Command not found: ", argv[3]);
		exit (127);
	}
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_outfile == -1)
		print_error("Bad outfile\n");
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd[WRITE_END]);
	if ((access(cmd[0], X_OK)) == 0)
		execve(path_real[0], path_real, NULL);
	else
		execve(path_real[0], cmd, NULL);
	perror("Error");
}

int	main(int argc, char **argv, char **env)
{
	int			fd[2];
	int			pid1;
	int			pid2;
	t_process	status;

	check_args(argv, argc, env);
	if (pipe(fd) == -1)
		print_error("Bad pipe\n");
	pid1 = fork();
	if (pid1 == 0)
		first_son_process(fd, argv, env);
	pid2 = fork();
	if (pid2 == 0)
		second_son_process(fd, argv, env);
	(close(fd[0]), close(fd[1]));
	waitpid(pid1, &status.status1, 0);
	waitpid(pid2, &status.status2, 0);
	if (status.status2 == 127)
		return (127);
	return (0);
}
