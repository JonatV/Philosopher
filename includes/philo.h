/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:35:57 by jveirman          #+#    #+#             */
/*   Updated: 2024/06/11 17:35:19 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

/*
#####################################################################
#								DEFINE								#
#####################################################################
*/
# define MSG_ERROR "\033[1;31m ERROR :\033[0m"
# define E_MUCH " Wrong number of argument"
# define E_NUM_EAT " Philosophers must eat at least 1 meal."
# define E_NUM_PHILO " Philosophers must be at least 1."
# define E_T_DIE " Philosophers must survive at least for 1ms."
# define E_T_EAT " Philosophers must eat at least for 1ms."
# define E_T_SLEEP " Philosophers must sleep at least for 1ms."

/*
#####################################################################
#							STRUCTURE								#
#####################################################################
*/

typedef struct s_config
{
	int	error;
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_to_eat;
}	t_conf;

/*
#####################################################################
#						FUNCTIONS PROTOTYPE							#
#####################################################################
*/
/*----------------				PARSE				---------------*/
t_conf	parse_party(int c, char **v);

#endif
