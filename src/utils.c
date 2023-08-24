/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:20:46 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/24 09:30:26 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/// @brief count the number of char in a string
/// @param str the tring
/// @return the string length
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/// @brief Check if c it's a space
/// @param c is a char
/// @return 1 = true 0 = false
static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\r' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

/// @brief Check if it's an number
/// @param c is a char
/// @return 1 = true 0 = false
static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check(char *str, int i)
{
	int	res;

	res = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

/// @brief alphabet to integer
/// @param str is a string whit dedgit
int	ft_atoi(const char *str)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	return (check((char *)str, i) * sign);
}

static long int	check1(char *str, long int i)
{
	long int	res;

	res = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

/// @brief alphabet to long integer
/// @param str is a string whit dedgit
long int	ft_atoli(const char *str)
{
	int			sign;
	long int	i;

	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	return (check1((char *)str, i) * sign);
}
