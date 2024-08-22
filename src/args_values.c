/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:12:54 by wiljimen          #+#    #+#             */
/*   Updated: 2024/08/22 16:45:24 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_value(int n, char *str)
{
	perror(str);
	exit(n);
}

void	check_args(char **argv, int argc, char **env)
{
	if (argc != 5)
		exit_value(1, "More or less than 5 arguments");
	if (!argv[2][0] && !argv[3][0])
		exit_value(126, "Permission denied");
	if (!argv[3][0])
		exit_value(127, "Permission denied");
	if (!argv[2][0])
		ft_printf("Permission denied\n");
	if (!*env)
		exit_value(EXIT_FAILURE, "Error");
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
