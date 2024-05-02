/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:57:51 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/18 17:15:22 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	c1 = c;
	i = 0;
	while (s[i] != c1 && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == c1)
		return ((char *)s + i);
	return (NULL);
}
