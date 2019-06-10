/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:32:24 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 15:43:49 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wordcut(char const *s, char split, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = -1;
	k = 0;
	while (++j < ft_strlen(s))
	{
		if (s[j] != split && s[j] != '\0')
		{
			i++;
			while (s[j] != split && s[j] != '\0')
			{
				if (i == n)
					k++;
				j++;
			}
			if (k)
				break ;
		}
	}
	return (ft_strsub(s, (j - k), k));
}
