/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:50:58 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 17:07:20 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if ((!s1 || !s2) && n == 0)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (str1[i] == str2[i] && i < (n - 1))
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return (str1[i] - str2[i]);
}
