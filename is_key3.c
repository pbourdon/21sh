/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:10:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:10:14 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int	is_left_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68 && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}

int	is_right_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67 && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}

int	is_enter_key(char *buffer)
{
	if (buffer[0] == 10 && buffer[1] == 0)
		return (1);
	return (0);
}

int	is_home_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 72 && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}

int	is_end_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 70 && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}
