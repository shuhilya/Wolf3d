/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:22:00 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/06 18:09:07 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	symb;
	int		i;

	symb = (char)c;
	str = (char*)s;
	i = (int)ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == symb)
			return (str + i);
		i--;
	}
	return (NULL);
}
