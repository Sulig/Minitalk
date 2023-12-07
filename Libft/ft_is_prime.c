/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:35:52 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/24 13:34:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_prime(size_t num)
{
	size_t	div;

	div = 2;
	while (div < num)
	{
		if (!(num % div))
			if (div != num)
				return (0);
		div++;
	}
	return (1);
}
