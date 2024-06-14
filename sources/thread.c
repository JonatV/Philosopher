/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:33:02 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/14 16:51:17 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	all_philo_are_fed(t_philo *philos)
{
	int	i;
	
	i = 0;
	while (i < philos[i].num_philos)
	{
		pthread_mutex_lock(philos[i].m_meal);
		if (philos[i].num_eaten < philos[i].num_to_eat)
		{
			pthread_mutex_unlock(philos[i].m_meal);
			i++;
			return (0);
		}
		pthread_mutex_unlock(philos[i].m_meal);
		i++;
	}
	pthread_mutex_lock(philos->m_finish);
	*(philos->end_marker) = 1;
	pthread_mutex_unlock(philos->m_finish);
	return (1);
}

void	*monitoring(void *data)
{
	t_philo *philos;

	philos = (t_philo *)data;
	while (1)
	{
		if (all_philo_are_fed(philos))
			break ;
	}
	ft_putstr(MSG_GOOD);
	return (data);
}

void	create(t_prog *prog, t_mutex *m_forks)
{
	(void)m_forks; //debug
	int	i;
	pthread_t	the_watcher;

	i = 0;
	while (i < prog->num_philo)
	{
		if(pthread_create(&prog->philos[i].thread, NULL, &routine, &prog->philos[i]) != 0)
		{
			ft_putendl_fd(MSG_ERROR, 2);
			ft_putendl_fd(E_THRCREATE, 2);
		}
		i++;
	}
	pthread_create(&the_watcher, NULL, &monitoring, prog->philos);
	pthread_join(the_watcher, NULL);
	i = 0;
	while (i < prog->num_philo)
	{
		pthread_join(prog->philos[i].thread, NULL);
		i++;
	}
}

