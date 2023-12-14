/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:39:28 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/14 19:52:32 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <sys/types.h> 
#include <signal.h>
#include "../Libft/libft.h"

static int	ft_send_bits(char c, int pid)
{
	size_t	i;
	size_t	bit;

	i = 8;
	while (i--)
	{
		bit = (c >> i) & 1;
		if (!bit)
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		if (bit)
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		usleep(50);
	}
	return (1);
}

static int	ft_send_str(char *mess, int pid)
{
	size_t	i;

	i = 0;
	if (!mess || !ft_strllen(mess))
	{
		ft_printf("Nothing to send\n");
		exit(1);
	}
	while (mess[i])
	{
		if (!ft_send_bits(mess[i], pid))
			return (0);
		usleep(50);
		i++;
	}
	ft_send_bits('\0', pid);
	return (1);
}

static void	ft_confirm(int sig)
{
	static size_t	bits;

	if (sig == SIGUSR2)
		bits++;
	else if (sig == SIGUSR1)
	{
		bits -= 8;
		ft_printf("Sended %u bits\n", bits);
		exit(0);
	}
}

static int	ft_is_all_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **args)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("\033[1;31mWrong number of arguments!\n");
		ft_printf("\033[1;33mRun like these:\n%s <PID> <Message>\n", args[0]);
		exit(1);
	}
	if (!ft_is_all_num(args[1]))
	{
		ft_printf("\033[1;31mPID is invalid!\n");
		exit(1);
	}
	pid = ft_atoi(args[1]);
	signal(SIGUSR1, ft_confirm);
	signal(SIGUSR2, ft_confirm);
	if (!ft_send_str(args[2], pid))
	{
		ft_printf("\033[1;31mWrong PID\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
