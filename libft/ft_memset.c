/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:14:01 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/04 19:28:50 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	symb;
	unsigned char	*src;

	i = 0;
	symb = (unsigned char)c;
	src = b;
	while (i < len)
	{
		src[i] = symb;
		i++;
	}
	return (b);
}
