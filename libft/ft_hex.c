/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:02:38 by wiljimen          #+#    #+#             */
/*   Updated: 2023/12/10 11:59:27 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_hexa_lower(unsigned int numx)
{
	int	i;

	i = 0;
	if (numx >= 16)
	{
		i += ft_hexa_lower(numx / 16);
		i += ft_hexa_lower(numx % 16);
	}
	else
	{
		if (numx < 10)
			i += ft_putchar(numx + 48);
		else
			i += ft_putchar(numx - 10 + 'a');
	}
	return (i);
}

int	ft_hexa_upper(unsigned int numbX)
{
	int	i;

	i = 0;
	if (numbX >= 16)
	{
		i += ft_hexa_upper(numbX / 16);
		i += ft_hexa_upper(numbX % 16);
	}
	else
	{
		if (numbX < 10)
			i += ft_putchar(numbX + 48);
		else
			i += ft_putchar(numbX - 10 + 'A');
	}
	return (i);
}
