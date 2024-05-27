/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:35 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/27 08:58:28 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	ft_protect_malloc(char *argv, char *str)
{
	if (!argv)
	{
		ft_printf("%s\n", str);
		free(argv);
	}
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
