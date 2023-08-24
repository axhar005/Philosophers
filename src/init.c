/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:28:12 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/24 15:24:57 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philo(void)
{
	size_t	i;

	i = 0;
	while (i < data()->number_of_philo)
	{
		pthread_join(data()->philo[i].thread, NULL);
		i++;
	}
}

void	create_philo(void)
{
	size_t	i;

	i = 0;
	while (i < data()->number_of_philo)
	{
		data()->philo[i].last_eat = get_time() + data()->time_to_die;
		pthread_create(&data()->philo[i].thread, NULL, routine,
			&data()->philo[i]);
		i++;
	}
}

void	init_mutex(int action)
{
	size_t	i;

	i = 0;
	pthread_mutex_init(&data()->mutex.death, NULL);
	pthread_mutex_init(&data()->mutex.print, NULL);
	pthread_mutex_init(&data()->mutex.last_eat, NULL);
	pthread_mutex_init(&data()->mutex.fork, NULL);
	while (i < data()->number_of_philo)
	{
		if (action == INIT)
		{
			pthread_mutex_init(&data()->philo[i].my.fork, NULL);
		}
		else if (action == DEL)
			pthread_mutex_destroy(&data()->philo[i].my.fork);
		i++;
	}
}

void	init_philo(void)
{
	size_t	i;

	i = 0;
	if (data()->max_eat > 0)
		data()->limited_eat = true;
	if (data()->number_of_philo == 1)
		data()->only_the_one = true;
	while (i < data()->number_of_philo)
	{
		data()->philo[i].id = i + 1;
		data()->philo[i].eat_number = data()->max_eat;
		if (i != data()->number_of_philo - 1)
			data()->philo[i].mate = &data()->philo[i + 1].my;
		else
			data()->philo[i].mate = &data()->philo[0].my;
		i++;
	}
}
