/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:22:25 by alicigar          #+#    #+#             */
/*   Updated: 2025/07/23 03:28:16 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	unsigned char	c;

	if (argc != 3)
	{
		write(2, "Error: invalid input\n", 20);
		return (1);
	}
	
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Error: Invalid PID\n", 18);
		return (1);
	}

	i = 0;
	while (argv[2][i])
	{
		c = argv[2][i];
		int bit = 8;
		while (bit--)
		{
			if ((c >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	c = '\0';
	int bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
	return (0);
}
