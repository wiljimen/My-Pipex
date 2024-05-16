/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/16 19:05:22 by wiljimen         ###   ########.fr       */
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
	while(str[i])
		i++;
	return (i);
}

char	**find_path(char **env)
{
	char	*path_save;
	char	**path_complete;
	int		i;

	path_save = NULL;
	path_complete = NULL;
	i = 0;
	while(*env)
	{
		if(ft_strnstr(*env, "PATH=", 5))
		{
			path_save = *env + 5;
			break ;
		}
		*env++;
	}
	path_complete = ft_split(path_save, ':');
	ft_protect(path_complete, "Free done in Path\n");
	while(path_complete[i])
	{
		path_complete[i] = ft_strjoin(path_complete[i], "/");
		i++;
	}
	return (path_complete);
}

char	**access_checker(char *argv, char **env)
{
	char	**path;
	char	**temp2;
	char	**path_real;
	
	path = find_path(env);
	path_real = ft_calloc(array_len(path) + 1, sizeof(char *));
	temp2 = ft_calloc(array_len(path) + 1, sizeof(char *));
	ft_protect(path_real, "Bad malloc:path_real");
	while(*path)
	{
		printf("MAMALO\n");
		*temp2 = ft_strjoin(*path, argv);
		ft_protect(temp2, "Temp2 free\n");
		if ((access(*temp2, X_OK)) == 0)
		{
			*path_real = *temp2;
			printf("%s\n", *path_real);
			*path_real++;
		}
		else
			free(*temp2);
		*temp2++;
		*path++;
		printf("%s\n", *path_real);
	}
	free(*temp2);
	return(path_real);
}


int	main(int argc, char **argv, char **env)
{
	if (argc != 2)
	{
		print_error("More or less than 5 arguments");
	}
	char	**path_real;
	path_real = access_checker(argv[1], env);
    return (0);
}
