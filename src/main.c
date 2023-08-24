/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:14:21 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/24 15:27:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(size_t philo_id, char *str)
{
	pthread_mutex_lock(&data()->mutex.print);
	if (!check_one_death())
		printf("%lld %zu %s\n", get_time(), philo_id, str);
	pthread_mutex_unlock(&data()->mutex.print);
}

void	check_eat(t_philo *philo)
{
	usleep(150);
	while (!check_key(philo) || philo->last_eat <= get_time())
	{
		if (philo->last_eat <= get_time())
		{
			check_all_dead(philo);
			return ;
		}
		if (check_one_death())
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&philo->my.fork);
	print_state(philo->id, FORK);
	pthread_mutex_lock(&philo->mate->fork);
	print_state(philo->id, FORK);
	print_state(philo->id, EATING);
	philo->last_eat = get_time() + data()->time_to_die;
	msleep(data()->time_to_eat, philo);
	pthread_mutex_unlock(&philo->my.fork);
	pthread_mutex_unlock(&philo->mate->fork);
	pthread_mutex_lock(&data()->mutex.fork);
	philo->my.lock = false;
	philo->mate->lock = false;
	pthread_mutex_unlock(&data()->mutex.fork);
}

bool	check_key(t_philo *philo)
{
	if (data()->only_the_one)
		return (false);
	pthread_mutex_lock(&data()->mutex.fork);
	if (!philo->my.lock && !philo->mate->lock)
	{
		philo->my.lock = true;
		philo->mate->lock = true;
		pthread_mutex_unlock(&data()->mutex.fork);
		return (true);
	}
	pthread_mutex_unlock(&data()->mutex.fork);
	return (false);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (!data()->limited_eat)
		return (NULL);
	if (philo->id % 2 == 0)
		msleep(10, philo);
	while (!check_one_death())
	{
		print_state(philo->id, THINKING);
		if (!check_one_death())
			check_eat(philo);
		if (philo->eat_number > 0 && data()->limited_eat)
			philo->eat_number--;
		if (philo->eat_number == 0 && data()->limited_eat)
			break ;
		if (!check_one_death())
		{
			print_state(philo->id, SLEEPING);
		}
		msleep(data()->time_to_sleep, philo);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (pars(ac, av))
		{
			init_mutex(INIT);
			init_philo();
			create_philo();
			join_philo();
		}
	}
	else
		printf("Error: bad arguments\n");
	return (0);
}
