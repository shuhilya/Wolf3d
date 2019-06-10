/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:20:53 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/06 17:55:58 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	symb;
	int		i;

	symb = (char)c;
	str = (char*)s;
	i = 0;
	while (i < (int)ft_strlen(str) + 1)
	{
		if (str[i] == symb)
			return (str + i);
		i++;
	}
	return (NULL);
}
