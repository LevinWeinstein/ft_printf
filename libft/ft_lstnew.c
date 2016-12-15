/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:03:18 by lweinste          #+#    #+#             */
/*   Updated: 2016/09/28 19:43:30 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
		lst->content = (NULL);
	else if ((lst->content = (void *)malloc(content_size + 1)) == NULL)
		lst->content = NULL;
	else
		ft_memcpy(lst->content, content, content_size);
	lst->next = NULL;
	return (lst);
}
