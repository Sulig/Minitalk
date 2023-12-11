/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:17:37 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/11 20:39:23 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_accepted(char c, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789ABCDEF";
	if (c >= 'a' && c <= 'f')
		c -= 32;
	while (i < base)
	{
		if (c == str[i])
			return (str[i] - '0');
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int		cnt;
	int		sign;
	int		find;

	cnt = -1;
	find = 0;
	sign = 1;
	while (str[++cnt] < 33)
		if ((str[cnt] < 9 || str[cnt] > 13) && str[cnt] != ' ')
			return ('\0');
	if (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == '-')
			sign *= -1;
		cnt++;
	}
	while (str[cnt] && (ft_accepted(str[cnt], base) != -1))
	{
		find *= base;
		find += ft_accepted(str[cnt], base);
		cnt++;
	}
	return (find * sign);
}
