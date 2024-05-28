/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/28 17:30:46 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0
# define WRITE_END 1

# include "libft.h"
# include <sys/wait.h>

void	print_error(char *str);
void	ft_free_two(char **argv);
void	ft_free(char **temp, char *str);
void	ft_protect(char **temp, char *str);
int		array_len(char **str);
char	**find_path(char **env);
char	**access_checker(char *argv, char **path);

#endif