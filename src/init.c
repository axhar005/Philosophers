/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:28:12 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/22 15:28:39 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void join_philo(void)
{
     size_t i;

	i = 1;
	while(i <= data()->number_of_philo)
	{
		pthread_join(data()->philo[i].thread, NULL);
		i++;
	}
}

void create_philo(void)
{
    size_t i;

	i = 1;
	while(i <= data()->number_of_philo)
	{
		pthread_create(&data()->philo[i].thread, NULL, routine, &data()->philo[i]);
		i++;
	}
}

void init_mutex(int action)
{
    size_t i;
    
    i = 1;
    while(i <= data()->number_of_philo)
    {
        if (action == INIT)
        {
            pthread_mutex_init(&data()->philo[i].fork, NULL);
        }
		else if (action == DEL)
			pthread_mutex_destroy(&data()->philo[i].fork);
		i++;
    }
}

void init_philo(void)
{
    size_t i;
	i = 1;
	while(i <= data()->number_of_philo)
	{
        data()->philo[i].id = i;
        data()->philo[i].last_eat = get_time();
		data()->philo[i].eat_number = data()->max_eat;
		if (i != data()->number_of_philo)
			data()->philo[i].mate_fork = data()->philo[i + 1].fork;
		else
			data()->philo[i].mate_fork = data()->philo[1].fork;
		i++;
	}
}