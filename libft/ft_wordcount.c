/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:25:00 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 15:43:38 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char split)
{
	int		i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char*)s;
	while (j < ft_strlen(s))
	{
		if (tmp[j] != split && tmp[j] != '\0')
		{
			while (tmp[j] != split && tmp[j] != '\0')
				j++;
			i++;
		}
		j++;
	}
	return (i);
}
