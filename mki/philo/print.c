/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:04:35 by mki               #+#    #+#             */
/*   Updated: 2021/06/27 17:57:26 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_time_num(t_global *global, int time, int number, char *str)
{
	char	*ret;
	
	pthread_mutex_lock(&global->mutex_print);
	if (global->monitor_flag == 0)
	{
		ret = ft_itoa(time);
		ft_putstr_fd(ret, 1);
		free(ret);
		write(1, " ", 1);
		ret = ft_itoa(number);
		ft_putstr_fd(ret, 1);
		free(ret);
		write(1, " ", 1);
		ft_putstr_fd(str, 1);
	}
	pthread_mutex_unlock(&global->mutex_print);
}

void	print_state(t_global *global, int time, int number, int state)
{
	if (state == TAKE)
		print_time_num(global, time, number + 1, "has taken a fork\n");
	else if (state == EAT)
		print_time_num(global, time, number + 1, "is eating\n");
	else if (state == SLEEP)
		print_time_num(global, time, number + 1, "is sleeping\n");
	else if (state == THINK)
		print_time_num(global, time, number + 1, "is thinking\n");
	else if (state == DIE)
		print_time_num(global, time, number + 1, "died\n");
}
