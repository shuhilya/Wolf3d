/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:57:54 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/06 18:58:11 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strnew;

	strnew = (char*)malloc(sizeof(char) * (size + 1));
	if (!strnew)
		return (NULL);
	ft_bzero(strnew, size + 1);
	return (strnew);
}
