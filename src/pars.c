/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:37:37 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/24 16:08:15 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	find_filter(char *str, char *filter)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str || !filter)
		return (-1);
	while (str[i])
	{
		j = 0;
		while (filter[j])
		{
			if (str[i] == filter[j])
				break ;
			j++;
		}
		if (j == ft_strlen(filter))
			return (1);
		i++;
	}
	return (0);
}

static bool	max_min_arg(void)
{
	if (data()->number_of_philo > 200)
		return (false);
	if (data()->time_to_die < 60)
		return (false);
	if (data()->time_to_eat < 60)
		return (false);
	if (data()->time_to_sleep < 60)
		return (false);
	return (true);
}

bool	pars(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 6)
		data()->max_eat = -1;
	while (av[++i])
	{
		if (ft_atoli(av[i]) > INT_MAX)
			return (false);
		else if (find_filter(av[i], "0123456789"))
			return (false);
		if (i == 1)
			data()->number_of_philo = ft_atoi(av[i]);
		else if (i == 2)
			data()->time_to_die = ft_atoi(av[i]);
		else if (i == 3)
			data()->time_to_eat = ft_atoi(av[i]);
		else if (i == 4)
			data()->time_to_sleep = ft_atoi(av[i]);
		else if (i == 5)
			data()->max_eat = ft_atoi(av[i]);
	}
	if (!max_min_arg())
		return (false);
	return (true);
}
