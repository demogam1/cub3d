/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:25:08 by misaev            #+#    #+#             */
/*   Updated: 2021/04/07 18:16:23 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p_courant;
	t_list	*tmp;

	if (lst)
	{
		p_courant = *lst;
		while (p_courant)
		{
			tmp = p_courant -> next;
			ft_lstdelone(p_courant, del);
			p_courant = tmp;
		}
		*lst = NULL;
	}
}
