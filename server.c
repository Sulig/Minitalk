/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:42 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/11 20:39:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <signal.h>
#include "./Libft/libft.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	while (1)
	{
		ft_printf("PID: %i\n", pid);
		pause();
	}
	return (0);
}
