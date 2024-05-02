/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:04:57 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/18 17:14:50 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf_counter(va_list args, const char type)
{
	int		counter;

	counter = 0;
	if (type == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (type == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		counter += ft_put_ptr(va_arg(args, int *));
	else if (type == 'd' || type == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		counter += ft_putunbr(va_arg(args, unsigned int));
	else if (type == 'x')
		counter += ft_hexa_lower(va_arg(args, unsigned int));
	else if (type == 'X')
		counter += ft_hexa_upper(va_arg(args, unsigned int));
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				counter += write(1, "%%", 1);
			else
				counter += ft_printf_counter(args, str[i]);
		}
		else
			counter += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (counter);
}
