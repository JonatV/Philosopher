/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:35:57 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/12 21:19:27 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

/*
#####################################################################
#								DEFINE								#
#####################################################################
*/
# define MSG_ERROR "\033[1;31m ERROR :\033[0m"
# define E_MUCH " Wrong number of argument"
# define E_NUM_EAT " Philosophers must eat at least 1 meal."
# define E_NUM_PHILO " Philosophers must be at least 1 and max 200."
# define E_T_DIE " Philosophers must survive at least for 1ms."
# define E_T_EAT " Philosophers must eat at least for 1ms."
# define E_T_SLEEP " Philosophers must sleep at least for 1ms."
# define MAX_PHILO 200

/*
#####################################################################
#							STRUCTURE								#
#####################################################################
*/
typedef pthread_mutex_t	t_mutex;

typedef struct s_config
{
	int	error;
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_to_eat;
}	t_conf;

typedef struct s_philo
{
	pthread_t			thread;
	int					current;
	long				*start_time;
	t_mutex				*m_dead;
	t_mutex				*m_meal;
	t_mutex				*m_msg;
	t_mutex				*m_left_fork;
	t_mutex				*m_right_fork;
	int					need_for_burial;
	int					num_eaten;
	struct s_program	*program;
}	t_philo;

typedef struct s_program
{
	int			is_dead;
	int			num_philo;
	long		start_time;
	t_philo		*philos;
	t_mutex		m_dead;
	t_mutex		m_meal;
	t_mutex		m_msg;
	t_conf		*conf;
}	t_prog;

/*
#####################################################################
#						FUNCTIONS PROTOTYPE							#
#####################################################################
*/
/*----------------				PARSE				---------------*/
t_conf	parse_party(int c, char **v);

/*----------------				INIT				---------------*/
void	init(t_prog *prog, t_conf *conf, t_mutex *m_forks, t_philo *philos);

#endif
