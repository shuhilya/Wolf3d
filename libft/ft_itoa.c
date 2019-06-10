/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:19:17 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 13:10:31 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_return(int j, char *s, \
		unsigned int nbr, unsigned int sign)
{
	while (j)
	{
		s[ft_count_razryad(nbr) + sign - 1] = (nbr % 10 + '0');
		nbr = nbr / 10;
		j--;
	}
	return (s);
}

char				*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*s;
	unsigned int	sign;
	int				j;

	sign = 0;
	if (n < 0)
	{
		sign++;
		nbr = -n;
	}
	else
		nbr = n;
	if (sign)
		s = (char*)malloc(sizeof(char) * ft_count_razryad(nbr) + 2);
	else
		s = (char*)malloc(sizeof(char) * ft_count_razryad(nbr) + 1);
	if (!s)
		return (0);
	if (sign)
		s[0] = '-';
	s[ft_count_razryad(nbr) + sign] = '\0';
	j = ft_count_razryad(nbr);
	return (ft_return(j, s, nbr, sign));
}
