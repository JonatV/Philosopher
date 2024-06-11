/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:57:44 by jveirman          #+#    #+#             */
/*   Updated: 2024/05/27 14:13:19 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	int	i;

	if (!s || !s[0])
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i++], 1);
	}
}
