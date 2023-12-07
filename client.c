/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:37:14 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/07 19:30:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <signal.h>
#include "./Libft/libft.h"

void	ft_print_binary(char *mess)
{
	size_t	i;
	int		dec;
	char	*bin;

	i = 0;
	while (mess[i])
	{
		bin = ft_unsig_tobase(mess[i], 'b');
		if (bin)
		{
			dec = ft_atoi(bin);
			ft_printf("Char: %c -> Dec: %i -> Bin: %s\n", mess[i], dec, bin);
			free(bin);
		}
		i++;
	}
}

int	main(int argc, char **args)
{
	if (argc != 3)
	{
		ft_printf("\033[1;31mWrong number of arguments!\n");
		ft_printf("\033[1;33mRun like these:\n%s <PID> <Message>\n", args[0]);
		exit(0);
	}
	ft_print_binary(args[2]);
	return (0);
}
