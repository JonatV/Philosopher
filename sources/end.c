/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/14 16:32:33 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	end(t_prog *prog, t_mutex *forks)
{
	int	i;

	i = 0;
	while (i < prog->num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&prog->m_finish);
	pthread_mutex_destroy(&prog->m_meal);
	pthread_mutex_destroy(&prog->m_msg);
}
