/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:50:02 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/06 18:20:11 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	int		i;
	int		j;

	h = (char*)haystack;
	n = (char*)needle;
	i = 0;
	if (!ft_strlen(n))
		return ((char*)h);
	while (h[i])
	{
		j = 0;
		while (h[i + j] && n[j] && h[i + j] == n[j])
			j++;
		if (!n[j])
			return (h + i);
		i++;
	}
	return (0);
}
