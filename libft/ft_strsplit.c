/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:27:10 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 15:43:06 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_arrfill(char **arr, char const *s, char split, int count)
{
	char			*tmp;
	unsigned int	i;
	int				k;
	size_t			p;

	k = 0;
	i = -1;
	tmp = (char*)s;
	while (++i < ft_strlen(s) && k < count)
	{
		p = 0;
		if (tmp[i] != split)
		{
			while (tmp[i] != split && tmp[i] != '\0')
			{
				p++;
				i++;
			}
			i = i - p;
			arr[k] = ft_strsub(tmp, i, p);
			k++;
			i = i + p;
		}
	}
	arr[k] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s || !c)
		return (0);
	i = ft_wordcount(s, c);
	result = (char**)malloc(sizeof(char*) * (i + 1));
	if (!result)
		return (0);
	ft_arrfill(result, s, c, i + 1);
	return (result);
}
