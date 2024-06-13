/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:59:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/13 19:30:03 by jveirman         ###   ########.fr       */
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
void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		sleeping(philo);
		eat(philo);
		think(philo);
	}
}

static void	sleeping(t_philo *philo)
{
	state_msg(MSG_SLEEP, philo);
	usleep(philo->time_to_sleep);
}

static void	eat(t_philo *philo)
{
	state_msg(MSG_EAT, philo);
}

static void	think(t_philo *philo)
{
	state_msg(MSG_THINK, philo);
}
