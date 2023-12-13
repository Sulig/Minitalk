/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:34:44 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/13 20:50:39 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <signal.h>
#include "../Libft/libft.h"

/*
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
*/

void	ft_print_sig(int sig)
{
	static char	ch;
	static int	bit = 7;

	if (bit == 7)
		ch = 0;
	if (sig == SIGUSR2)
		ch |= (1 << bit);
	bit--;
	if (bit == 1)
	{
		ft_printf("%c", ch);
		bit = 7;
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
