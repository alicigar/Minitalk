/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:22:30 by alicigar          #+#    #+#             */
/*   Updated: 2025/07/23 03:30:23 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int sig)
{
	static unsigned char	c;
	static int				bit_count;

	if (sig == SIGUSR1)
		c = c | (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if(c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	write(1, "This is alicigar's Minitalk :)\n", 31);
	write(1, "\nYour PID is: ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
