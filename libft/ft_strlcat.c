/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:29:38 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/04 19:39:52 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dest_size;
	size_t	i;

	dest_size = 0;
	while (dest[dest_size] != '\0' && dest_size < size)
		dest_size++;
	src_size = 0;
	i = 0;
	while (src[src_size])
	{
		if (src_size + dest_size + 1 < size)
		{
			dest[dest_size + i] = src[src_size];
			i++;
		}
		src_size++;
	}
	if (dest_size < size)
		dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
