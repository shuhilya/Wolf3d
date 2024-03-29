/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:34:33 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/08 16:59:10 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t i;

	if (!s)
		return ;
	i = 0;
	while (i < ft_strlen(s))
	{
		ft_putchar(s[i]);
		i++;
	}
}
