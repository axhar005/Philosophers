#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define INIT 0
# define DEL 1

# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef long long int	t_time;

typedef struct s_mutex
{
	pthread_mutex_t		print;
	pthread_mutex_t		death;
	pthread_mutex_t		last_eat;
}						t_mutex;

typedef struct s_philo
{
	pthread_mutex_t		fork;
	pthread_mutex_t		*mate_fork;
	pthread_t			thread;
	size_t				id;
	int					eat_number;
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
	bool				limited_eat;
	bool				only_the_one;
	t_philo				philo[300];
	t_mutex				mutex;
}						t_data;

size_t					ft_strlen(const char *str);
int						find_filter(char *str, char *filter);
bool					pars(char **av);
t_data					*data(void);
int						ft_atoi(const char *str);
t_time					get_time(void);
void					*routine(void *param);
void					print_state(size_t philo_id, char *str);
void					msleep(t_time duration, t_philo *philo);
long int				ft_atoli(const char *str);

// init

void					join_philo(void);
void					create_philo(void);
void					init_mutex(int action);
void					init_philo(void);

// checks

bool					check_one_death(void);
bool					check_all_dead(t_philo *philo);

#endif