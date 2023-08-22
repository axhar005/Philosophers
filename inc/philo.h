#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/time.h>

# define INIT 0
# define DEL 1

# define FORK "has taken a fork"
# define EATINT "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef long long int	t_time;

typedef struct s_mutex
{
	pthread_mutex_t		print;
	pthread_mutex_t		death;
	pthread_mutex_t		dead;
}						t_mutex;

typedef struct s_philo
{
	pthread_mutex_t		fork;
	pthread_t			thread;
	size_t				id;
	size_t				eat_number;
	t_time				last_eat;

}						t_philo;

typedef struct s_data
{
	size_t				number_of_philo;
	t_time				time_to_eat;
	t_time				time_to_die;
	t_time				time_to_sleep;
	size_t				max_eat;
	bool				death;
	t_philo				philo[200];
	t_mutex				mutex;
}						t_data;

size_t					ft_strlen(const char *str);
int						find_filter(char *str, char *filter);
bool					pars(char **av);
t_data					*data(void);
int						ft_atoi(const char *str);
t_time					get_time(void);
void					*routine(void *param);

//init

void					join_philo(void);
void					create_philo(void);
void					init_mutex(int action);
void					init_philo(void);

#endif