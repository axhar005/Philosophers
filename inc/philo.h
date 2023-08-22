#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INIT 0
# define DEL 1

typedef struct s_mutex
{
	pthread_mutex_t	print;
}					t_mutex;

typedef struct s_philo
{
	pthread_mutex_t	fork;
	pthread_t		thread_id;
	size_t			philo_id;
	size_t			eat_number;

}					t_philo;

typedef struct s_data
{
	size_t			number_of_philo;
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			max_eat;
	bool			death;
	t_philo			philo[200];
	t_mutex			mutex;
}					t_data;

size_t				ft_strlen(const char *str);
int					find_filter(char *str, char *filter);
bool				pars(char **av);
t_data				*data(void);
int					ft_atoi(const char *str);

#endif