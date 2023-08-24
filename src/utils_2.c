/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:27:58 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/24 15:28:01 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long int	check1(char *str, long int i)
{
	long int	res;

	res = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

/// @brief alphabet to long integer
/// @param str is a string whit dedgit
long int	ft_atoli(const char *str)
{
	int			sign;
	long int	i;

	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	return (check1((char *)str, i) * sign);
}

t_data	*data(void)
{
	static t_data	dt;

	return (&dt);
}

void	msleep(t_time duration, t_philo *philo)
{
	t_time	start;

	start = get_time();
	if (philo->last_eat < start + duration && !check_one_death())
	{
		usleep((philo->last_eat - start) * 1000);
		check_all_dead(philo);
	}
	else
	{
		usleep(duration * 900);
		while (get_time() < duration + start)
			;
	}
}

t_time	get_time(void)
{
	static struct timeval	start = {-1, -1};
	struct timeval			real_time;

	if (start.tv_sec == -1 && start.tv_usec == -1)
		gettimeofday(&start, NULL);
	gettimeofday(&real_time, NULL);
	return ((real_time.tv_sec * 1000 - start.tv_sec * 1000) + real_time.tv_usec
		/ 1000 - start.tv_usec / 1000);
}
