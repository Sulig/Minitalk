/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:06 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/13 13:23:34 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dest;

	dest = (char *) s;
	while (n--)
		dest[n] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*call;

	call = malloc(count * size);
	if (call == 0)
		return (0);
	ft_bzero(call, count * size);
	return (call);
}
