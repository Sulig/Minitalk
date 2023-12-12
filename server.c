/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:42 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/12 15:22:36 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <signal.h>
#include "./Libft/libft.h"

void	ft_print_sig(int sig)
{
	ft_printf("signal %d recived\n", sig);
}

int	main(void)
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, ft_print_sig);
	while (1)
		pause();
	return (0);
}
