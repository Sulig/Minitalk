/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:34:44 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/14 18:50:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../Libft/libft.h"

static void	ft_print_sig(int sig, siginfo_t *t_sig_info, void *oact)
{
	static char	ch;
	static int	bit = 7;

	(void)oact;
	if (bit == 7)
		ch = 0;
	if (sig == SIGUSR2)
		ch |= (1 << bit);
	kill(t_sig_info->si_pid, SIGUSR2);
	bit--;
	if (bit == -1)
	{
		ft_printf("%c", ch);
		if (!ch)
			kill(t_sig_info->si_pid, SIGUSR1);
		bit = 7;
	}
}

int	main(void)
{
	struct sigaction	s_sig;

	ft_printf("PID: %i\n", getpid());
	s_sig.sa_sigaction = ft_print_sig;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (1)
		pause();
	return (0);
}
