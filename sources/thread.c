/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:33:02 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/13 18:57:59 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// pthread_create(the_pthread, NULL, the_function, the_data_to_the_function)

void	create(t_prog *prog, t_mutex *m_forks)
{
	(void)m_forks; //debug
	int	i;

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
}
