/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/08/22 18:23:07 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0
# define WRITE_END 1

# include "libft.h"
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_process
{
	int	num_error;
	int	status1;
	int	status2;
}				t_process;

void	ft_free_two(char **argv);
void	ft_free(char **temp);
void	ft_protect(char **temp);
int		array_len(char **str);
char	*get_path(char **env);
char	**find_path(char **env);
char	**access_checker(char *argv, char **path);
void	ft_error(int error_num);
void	exit_value(int n, char *str);
void	check_args(char **argv, int argc, char **env);

#endif