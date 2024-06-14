/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:49:47 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:40 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int c, char *v[])
{
	t_conf			config;
	t_prog			program;
	t_philo			philos[MAX_PHILO];
	t_mutex			m_forks[MAX_PHILO];

	config = parse_party(c, v);
	if (config.error)
		return (EXIT_FAILURE);
	init(&program, &config, m_forks, philos);
	create(&program, m_forks);
	end(&program, m_forks);
	return (0);
}
