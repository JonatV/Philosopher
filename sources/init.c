/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:59:57 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/13 19:01:13 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_forks(t_mutex *m_mutex, int num_philo);
void	init_program(t_prog *prog, t_conf *conf, t_philo *philos);
void	init_philos(t_prog *prog, t_mutex *m_mutex,t_philo *philos);

void	init(t_prog *prog, t_conf *conf, t_mutex *m_forks, t_philo *philos)
{
	init_program(prog, conf, philos);
	init_forks(m_forks, (*conf).num_philo);
	init_philos( prog, m_forks, philos);
}

void	init_program(t_prog *prog, t_conf *conf, t_philo *philos)
{
	pthread_mutex_init(&prog->m_dead, NULL);
	pthread_mutex_init(&prog->m_meal, NULL);
	pthread_mutex_init(&prog->m_msg, NULL);
	prog->philos = philos;
	prog->num_philo = (*conf).num_philo;
	prog->is_dead = 0;
	prog->start_time = what_time_is_it();
	prog->conf = conf;
}

void	init_forks(t_mutex *m_forks, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_init(&m_forks[i], NULL);
		i++;
	}
}

void	init_philos(t_prog *prog, t_mutex *m_mutex, t_philo *philos)
{
	(void)prog; //debug
	int	i;

	i = 0;
	while (i < prog->num_philo)
	{
		philos[i].current = i;
		philos[i].start_time = &prog->start_time;
		philos[i].num_eaten = 0;
		philos[i].need_for_burial = 0;
		philos[i].m_left_fork = &m_mutex[i];
		if (i)
			philos[i].m_right_fork = &m_mutex[i - 1];
		else
			philos[i].m_right_fork = &m_mutex[prog->num_philo - i];
		i++;
	}
}
