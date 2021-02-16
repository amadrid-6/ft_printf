/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:41:07 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/21 12:36:24 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newelem)
{
	t_list *current;

	if (!*lst)
	{
		*lst = newelem;
		return ;
	}
	current = ft_lstlast(*lst);
	current->next = newelem;
}
