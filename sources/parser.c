/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:05:45 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/11 17:36:28 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_conf	error_parse(t_conf *config)
{
	config->error = 1;
	ft_putendl_fd(MSG_ERROR, 1);
	ft_putendl_fd(" Wrong number of argument", 1);
	return (*config);
}

t_conf	parse_party(int c, char **v)
{
	t_conf	config;

	config.error = 0;
	if (!(c == 5 || c == 6))
		return (error_parse(&config));
	config.number_of_philosophers = ft_atoi(v[1]);
	config.time_to_die = ft_atoi(v[2]);
	config.time_to_eat = ft_atoi(v[3]);
	config.time_to_sleep = ft_atoi(v[4]);
	config.num_to_eat = -42;
	if (c == 6)
	{
		config.num_to_eat = ft_atoi(v[5]);
		if (config.num_to_eat < 0)
			return (error_parse(&config));
	}
	return (config);
}
