/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:54:39 by qtamaril          #+#    #+#             */
/*   Updated: 2020/11/18 10:46:41 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct		s_options
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				limit_count_eat;
	long int		start_time;
	sem_t			*sem_forks;
	sem_t			*sem_write;
	sem_t			*sem_steward;
	sem_t			*sem_time;
	sem_t			*sem_die;
	sem_t			*sem_stop;
	sem_t			*sem_count_eat;
	int				stop;
}					t_options;

typedef struct		s_philo
{
	int				id;
	long int		meal_time;
	int				limit_count_eat;
}					t_philo;

/*
** ft_num.c
*/

int					ft_atoi(const char *str);
int					ft_str_is_num(char *str);
char				*ft_itoa(long int n);

/*
** ft_put.c
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);

/*
** ft_str.c
*/

size_t				ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *s);
char				*ft_strjoin_new(char *s1, char *s2);
void				fork_error(void);

/*
** init_and_eats.c
*/

void				check_count_eat(pid_t *pids, int i);
int					init_options(int ac, char **av);
void				philo_eats(t_philo *philo);

/*
** utils.c
*/

void				print_change(int id, char *mes, int isend);
int					print_error(char *str);
int					check_options(int ac, char **av);
long int			get_millisecs(void);
void				ft_sleep(long int end_time);

t_options			g_options;

#endif
