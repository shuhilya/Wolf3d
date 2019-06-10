/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:48:02 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/06 21:52:48 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	tmp = (char*)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!tmp)
		return (0);
	ft_bzero(tmp, s1len + s2len + 1);
	ft_strcat(tmp, s1);
	ft_strcat(tmp, s2);
	return (tmp);
}
