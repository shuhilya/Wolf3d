/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:22:43 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/06 19:02:51 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;
	int		len;

	if (!s)
		return (0);
	len = 0;
	i = 0;
	while (s[len])
		len++;
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	while (i < len)
	{
		tmp[i] = f(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
