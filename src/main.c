/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:14:21 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/22 11:44:12 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	dt;

	return (&dt);
}

void *routine(void *param)
{
    // t_philo *philo;
    
    // philo = (t_philo *)param;
    // pthread_mutex_lock(&mutex);
    // while (philo->eat_number > 0)
    // {
    //     printf("id :%zu, val : %zu\n", philo->index, philo->eat_number);
    //     philo->eat_number--;
    // }
    // pthread_mutex_unlock(&mutex);
    // return(NULL);
}

void join_philo(void)
{
     size_t i;

	i = 0;
	while(i < data()->number_of_philo)
	{
		pthread_join(data()->philo[i], NULL);
		i++;
	}
}

void create_philo(void)
{
    size_t i;

	i = 0;
	while(i < data()->number_of_philo)
	{
		pthread_create(&data()->philo[i].thread_id, NULL, routine, &data()->philo[i])
		i++;
	}
}

void init_mutex(int action)
{
    size_t i;
    
    i = 0;
    while(i < data()->number_of_philo)
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
        data()->philo[i].philo_id = i;
		i++;
	}
}

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
    // if (ac == 5 || ac == 6)
    // {
        
    // }
    return (0);
}