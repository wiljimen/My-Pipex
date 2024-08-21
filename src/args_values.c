/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:12:54 by wiljimen          #+#    #+#             */
/*   Updated: 2024/08/21 17:42:08 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_value(int n, char *str)
{
	ft_putstr_fd(str, 1);
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
		print_error("Env Error\n");
}

void	print_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	code_error(char *str, char *cmd)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd(cmd, 1);
}
