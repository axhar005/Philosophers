/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:11 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/24 15:18:51 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_one_death(void)
{
	pthread_mutex_lock(&data()->mutex.death);
	if (data()->death == true)
	{
		pthread_mutex_unlock(&data()->mutex.death);
		return (true);
	}
	pthread_mutex_unlock(&data()->mutex.death);
	return (false);
}

bool	check_all_dead(t_philo *philo)
{
	pthread_mutex_lock(&data()->mutex.death);
	if (data()->death == false)
	{
		data()->death = true;
		pthread_mutex_unlock(&data()->mutex.death);
		pthread_mutex_lock(&data()->mutex.print);
		printf("%lld %zu %s\n", get_time(), philo->id, DIED);
		pthread_mutex_unlock(&data()->mutex.print);
		return (true);
	}
	pthread_mutex_unlock(&data()->mutex.death);
	return (false);
}
