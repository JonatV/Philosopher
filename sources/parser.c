/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:05:45 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/13 15:24:37 by jveirman         ###   ########.fr       */
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

static int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static t_conf	check_config(t_conf *config, char **v)
{
	if (config->num_philo <= 0 || config->num_philo > MAX_PHILO \
	|| is_str_digit(v[1]))
		return (error_parse(config, E_NUM_PHILO));
	if (config->time_to_die <= 0 || is_str_digit(v[2]))
		return (error_parse(config, E_T_DIE));
	if (config->time_to_eat <= 0 || is_str_digit(v[3]))
		return (error_parse(config, E_T_EAT));
	if (config->time_to_sleep <= 0 || is_str_digit(v[4]))
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
		if (config.num_to_eat <= 0 || is_str_digit(v[5]))
			return (error_parse(&config, E_NUM_EAT));
	}
	return (check_config(&config, v));
}
