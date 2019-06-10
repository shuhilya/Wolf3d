/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:42:53 by bwynton-          #+#    #+#             */
/*   Updated: 2018/12/10 15:39:15 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_return(int i, long n, const char *str)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((n >= 0) && (n * 10 + (str[i] - '0') >= 0))
			n = n * 10 + (str[i] - '0');
		else if ((n < 0) && (n * 10 - (str[i] - '0') < 0))
			n = n * 10 - (str[i] - '0');
		else
			return (-1 * (n > 0));
		i++;
	}
	return (n);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	n;

	n = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		n = -1;
	}
	else if (str[i] == '+')
	{
		i++;
		n = 1;
	}
	else
		n = 1;
	while (str[i] == '0')
		i++;
	if ((str[i] < '0') || (str[i] > '9'))
		return (0);
	n = n * (str[i++] - '0');
	return (ft_return(i, n, str));
}
