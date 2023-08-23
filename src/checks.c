/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:11 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/23 16:39:05 by oboucher         ###   ########.fr       */
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

bool check_all_dead(t_philo *philo)
{
    pthread_mutex_lock(&data()->mutex.death);
    if (get_time() - philo->last_eat > data()->time_to_die)
    {
        pthread_mutex_lock(&data()->mutex.print);
        if (data()->death == false)
            printf("%lld %zu %s\n", get_time(), philo->id, DIED);
        pthread_mutex_unlock(&data()->mutex.print);
        data()->death = true;
        pthread_mutex_unlock(&data()->mutex.death);
        return (true);
    }
    pthread_mutex_unlock(&data()->mutex.death);
    return (false);
}