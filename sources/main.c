/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:49:47 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/13 19:51:58 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int c, char *v[])
{
	t_conf			config;
	t_prog			program;
	t_philo			philos[MAX_PHILO];
	t_mutex			m_forks[MAX_PHILO];
	int				i;

	config = parse_party(c, v);
	if (config.error)
		return (EXIT_FAILURE);
	init(&program, &config, m_forks, philos);
	create(&program, m_forks);
	i = 0;
	while (i < program.num_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	end(&program, m_forks);
	return (0);
}
