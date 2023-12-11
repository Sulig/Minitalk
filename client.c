/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:37:14 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/11 20:39:30 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <signal.h>
#include "./Libft/libft.h"

void	ft_print_binary(char *mess)
{
	size_t	i;
	char	*bin;

	i = 0;
	while (mess[i])
	{
		bin = ft_unsig_tobase(mess[i], 'x');
		while (ft_strlen(bin) < 8)
			bin = ft_strjoin_free_snd("0", bin);
		if (bin)
		{
			ft_printf("Sending char...\n%s\n", bin);
			free(bin);
		}
		i++;
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
	ft_print_binary(args[2]);
	return (0);
}
