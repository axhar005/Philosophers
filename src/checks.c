/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:11 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/22 23:27:56 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool check_one_death(void)
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

bool check_all_dead(void)
{
    size_t i;

    i = 1;
    pthread_mutex_lock(&data()->mutex.death);
    while (i < data()->number_of_philo)
    {
        if (get_time() - data()->philo[i].last_eat > data()->time_to_die)
        {
            if (data()->death == false)
            {
                print_state(i, DIED);
                data()->death = true;
                pthread_mutex_unlock(&data()->mutex.death);
                return (true);
            }
        }
        i++;
    }
    pthread_mutex_unlock(&data()->mutex.death);
    return (false);
}