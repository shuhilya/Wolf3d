/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:54:50 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 16:41:14 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	symb;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	symb = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == symb)
		{
			d[i] = s[i];
			return (dest + i + 1);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
