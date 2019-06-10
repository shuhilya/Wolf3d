/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:23:16 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/04 19:15:10 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;
	int		g;

	s = (char*)src;
	d = (char*)dest;
	i = -1;
	if (!len)
		return (dest);
	if (d < s)
		while (++i < len)
			d[i] = s[i];
	else
	{
		g = (int)len - 1;
		while (g >= 0)
		{
			d[g] = s[g];
			g--;
		}
	}
	return (dest);
}
