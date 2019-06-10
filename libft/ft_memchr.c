/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:42:35 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/04 19:29:24 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*str;
	size_t			i;

	symb = (unsigned char)c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == symb)
			return (str + i);
		i++;
	}
	return (NULL);
}
