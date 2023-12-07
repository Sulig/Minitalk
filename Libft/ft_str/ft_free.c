/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:11 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/21 13:20:33 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_auto_free_all(char ***arr)
{
	if (!ft_arr_strlen(*arr))
		if (*arr)
			free(*arr);
	if (ft_arr_strlen(*arr))
		arr[0] = ft_auto_free_arr(*arr);
	arr = NULL;
}

void	*ft_auto_free_arr(char **arr)
{
	size_t	size;

	size = ft_arr_strlen(arr);
	if (size)
	{
		while (size--)
		{
			if (arr[size])
				free(arr[size]);
			arr[size] = NULL;
		}
		free(arr);
	}
	arr = NULL;
	return (NULL);
}

void	*ft_free_str(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}
