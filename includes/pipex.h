/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/22 11:18:30 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
#include <sys/wait.h>

void	print_error(char *str);
void	ft_protect_malloc(char *argv, char *str);
void	ft_free(char **temp, char *str);
void	ft_protect(char **temp, char *str);
int		array_len(char **str);
char	**find_path(char **env);
char	**access_checker(char *argv, char **env, char **path);

#endif