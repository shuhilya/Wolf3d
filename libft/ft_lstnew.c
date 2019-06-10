/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:55:04 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/08 20:01:21 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	lstnew = (t_list*)malloc(sizeof(*lstnew));
	if (!lstnew)
		return (NULL);
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		lstnew->content = malloc(content_size);
		if (!lstnew->content)
			return (NULL);
		ft_memcpy(lstnew->content, (void*)content, content_size);
		lstnew->content_size = content_size;
	}
	lstnew->next = NULL;
	return (lstnew);
}
