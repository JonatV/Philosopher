/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:05:45 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/12 18:41:41 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_conf	error_parse(t_conf *config, char *msg)
{
	config->error = 1;
	ft_putendl_fd(MSG_ERROR, 1);
	ft_putendl_fd(msg, 1);
	return (*config);
}

static t_conf	check_config(t_conf *config) // wip: should it return a *t_conf
{
	if (config->num_philo <= 0)
		return (error_parse(config, E_NUM_PHILO));
	if (config->time_to_die <= 0)
		return (error_parse(config, E_T_DIE));
	if (config->time_to_eat <= 0)
		return (error_parse(config, E_T_EAT));
	if (config->time_to_sleep <= 0)
		return (error_parse(config, E_T_SLEEP));
	return (*config);
}

t_conf	parse_party(int c, char **v)
{
	t_conf	config;

	config.error = 0;
	if (!(c == 5 || c == 6))
		return (error_parse(&config, E_MUCH));
	config.num_philo = ft_atoi(v[1]);
	config.time_to_die = ft_atoi(v[2]);
	config.time_to_eat = ft_atoi(v[3]);
	config.time_to_sleep = ft_atoi(v[4]);
	config.num_to_eat = -1;
	if (c == 6)
	{
		config.num_to_eat = ft_atoi(v[5]);
		if (config.num_to_eat <= 0)
			return (error_parse(&config, E_NUM_EAT));
	}
	return(check_config(&config));
}
