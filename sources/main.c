/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:49:47 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/11 17:36:20 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int c, char *v[])
{
	t_conf	config;

	config = parse_party(c, v);
	if (config.error)
		return (EXIT_FAILURE);
	return (0);
}
