/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:12:54 by wiljimen          #+#    #+#             */
/*   Updated: 2024/08/22 18:43:29 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(int error_num)
{
	errno = error_num;
	perror("Error");
	exit(EXIT_FAILURE);
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
		perror("Permission denied\n");
	if (!*env)
		ft_error(ENXIO);
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

void	ft_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	exit(EXIT_FAILURE);
}

void	ft_protect(char **temp)
{
	if (!temp)
		ft_free(temp);
}
