/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:14:21 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/22 14:30:05 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	dt;

	return (&dt);
}

t_time    get_time(void)
{
    static struct timeval    start = {-1, -1};
    struct timeval            real_time;

    if (start.tv_sec == -1 && start.tv_usec == -1)
        gettimeofday(&start, NULL);
    gettimeofday(&real_time, NULL);
    return ((real_time.tv_sec * 1000 - start.tv_sec * 1000)
        + real_time.tv_usec / 1000 - start.tv_usec / 1000);
}

void    print_state(size_t philo_id, char *str)
{
    pthread_mutex_lock(&data()->mutex.print);
    printf("%lld %zu %s\n", get_time(), philo_id, str);
    pthread_mutex_unlock(&data()->mutex.print);
}

bool check_one_death()
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
            print_state(i, DIED);
            data()->death = true;
            return (true);
        }
        i++;
    }
    pthread_mutex_unlock(&data()->mutex.dead);
    return (false);
}

void *routine(void *param)
{
    t_philo *philo;
    
    philo = (t_philo *)param;
    if (philo->id % 2 == 0)
        usleep(1000);
    while (!check_one_death())
    {
        print_state(philo->id, THINKING);
        //eat
        //max eat
        //sleep
    }
    return(NULL);
}



int main(int ac, char **av)
{
    // (void)av;
    // (void)ac;
    if (ac == 5 || ac == 6)
    {
        if (pars(av))
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