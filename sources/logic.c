/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:59:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/14 16:54:03 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sleeping(t_philo *philo);
static void	eat(t_philo *philo);
static void	think(t_philo *philo);

/*
* INFO:
*	eat
*	sleep
*	think
*/
int	is_finish(t_philo *philo)
{
	pthread_mutex_lock(philo->m_finish);
	if (*(philo->end_marker) == 1)
	{
		pthread_mutex_unlock(philo->m_finish);
		return (1);
	}
	pthread_mutex_unlock(philo->m_finish);
	return (0);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->current % 2 == 0)
		usleep(1);
	while (!is_finish(philo))
	{
		sleeping(philo);
		eat(philo);
		think(philo);
	}
	return (data);
}

static void	sleeping(t_philo *philo)
{
	state_msg(MSG_SLEEP, philo);
	usleep(philo->time_to_sleep);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
	state_msg(MSG_L_FORK, philo);
	pthread_mutex_lock(philo->m_right_fork);
	state_msg(MSG_R_FORK, philo);
	state_msg(MSG_EAT, philo);
	usleep(philo->time_to_eat);
	philo->prev_meal = what_time_is_it();
	pthread_mutex_lock(philo->m_meal);
	philo->num_eaten++;
	pthread_mutex_unlock(philo->m_meal);
	printf("{%d} %d %s\n", philo->current, philo->num_eaten, "meal eaten");
	pthread_mutex_unlock(philo->m_left_fork);
	pthread_mutex_unlock(philo->m_right_fork);
}

static void	think(t_philo *philo)
{
	state_msg(MSG_THINK, philo);
}
