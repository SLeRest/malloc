/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:56:08 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/13 21:46:56 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*current;
	t_list	*next;

	if (!lst)
		return (NULL);
	begin = ft_lstnew((f(lst))->content, f(lst)->content_size);
	if (lst->next)
	{
		lst = lst->next;
		current = ft_lstnew(f(lst)->content, f(lst)->content_size);
		begin->next = current;
	}
	lst = lst->next;
	while (lst)
	{
		next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		current->next = next;
		current = next;
		lst = lst->next;
	}
	return (begin);
}
