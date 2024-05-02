/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:34:32 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/18 17:14:09 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	t_list	*res_f;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		res_f = f(lst->content);
		tmp = ft_lstnew(res_f);
		if (!tmp)
		{
			ft_lstclear(&result, del);
			del(res_f);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
