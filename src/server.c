/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:42 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/13 14:33:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <signal.h>
#include "../Libft/libft.h"

void	ft_print_sig(int sig)
{
	static char	bin[8];
	static int	bit = 0;

	if (bit == 0)
		ft_bzero(bin, 8);
	if (sig == SIGUSR1)
		bin[bit] = '0';
	else if (sig == SIGUSR2)
		bin[bit] = '1';
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", ft_atoi_base(bin, 2));
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, ft_print_sig);
	signal(SIGUSR2, ft_print_sig);
	while (1)
		pause();
	return (0);
}
