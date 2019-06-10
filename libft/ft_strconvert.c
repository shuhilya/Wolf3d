/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:44:59 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 16:04:31 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strconvert(const char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	tmp = malloc(sizeof(char) * ft_strlen(s) + 1);
	tmp[ft_strlen(s)] = '\0';
	while (j >= 0)
	{
		tmp[i] = s[j];
		i++;
		j--;
	}
	return (tmp);
}
