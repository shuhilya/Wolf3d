/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:17:46 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/08 19:02:04 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	i;
	size_t	j;

	h = (char*)haystack;
	n = (char*)needle;
	i = 0;
	if (!ft_strlen(n))
		return (h);
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] && n[j] && h[i + j] == n[j] && i + j < len)
			j++;
		if (!n[j])
			return (h + i);
		i++;
	}
	return (0);
}
