/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amadrid- <amadrid-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:19:38 by amadrid-          #+#    #+#             */
/*   Updated: 2020/07/21 12:37:55 by amadrid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newelem;

	newelem = (t_list *)malloc(sizeof(t_list));
	if (newelem == 0)
		return (NULL);
	newelem->content = content;
	newelem->next = NULL;
	return (newelem);
}
