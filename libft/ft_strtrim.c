/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:53:31 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/08 17:10:18 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	if (!s)
		return ("");
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = ft_strlen(s);
	if (i < len)
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		{
			len--;
			j++;
		}
	len = ft_strlen(s);
	tmp = (char*)malloc(sizeof(char) * (len - i - j + 1));
	if (!tmp)
		return (0);
	ft_memmove(tmp, s + i, len - i - j);
	tmp[len - i - j] = '\0';
	return (tmp);
}
