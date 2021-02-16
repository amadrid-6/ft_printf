/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:28:26 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/21 12:36:54 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *node)
{
	if (!*alst)
	{
		*alst = node;
		return ;
	}
	if (!node)
		return ;
	node->next = (*alst);
	(*alst) = node;
}
