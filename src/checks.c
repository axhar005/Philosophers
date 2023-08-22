/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:11 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/22 15:51:40 by oboucher         ###   ########.fr       */
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

    i = 0;
    pthread_mutex_lock(&data()->mutex.dead);
    while (i < data()->number_of_philo)
    {
        if (get_time() - data()->philo[i].last_eat > data()->time_to_die)
        {
            if (!check_one_death())
                print_state(i, DIED);
            if (!check_one_death())
                data()->death = true;
            return (true);
        }
        i++;
    }
    pthread_mutex_unlock(&data()->mutex.dead);
    return (false);
}