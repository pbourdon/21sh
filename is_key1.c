/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:09:58 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:10:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int	is_option_v(char *buffer)
{
	if (buffer[0] == -30 && buffer[1] == -120 && buffer[2] == -102 && \
			buffer[3] == 0)
		return (1);
	return (0);
}

int	is_option_right(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && \
			buffer[3] == 67)
		return (1);
	return (0);
}

int	is_option_left(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && \
			buffer[3] == 68)
		return (1);
	return (0);
}

int	is_option_key(char *buffer)
{
	if (is_option_left(buffer) || is_option_right(buffer) || \
			is_option_v(buffer) || is_option_c(buffer))
		return (1);
	return (0);
}

int	is_eot(char *buffer)
{
	if (buffer[0] == 4 && buffer[1] == 0)
		return (1);
	return (0);
}
