/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:10:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:10:07 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int	is_delete_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 51 && \
			buffer[3] == 126 && buffer[4] == 0)
		return (1);
	return (0);
}

int	is_backspace_key(char *buffer)
{
	if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0 && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}

int	is_direction_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && (buffer[2] == 66 || \
			buffer[2] == 65 || buffer[2] == 67 || buffer[2] == 68) && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}

int	is_down_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66 && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}

int	is_up_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65 && \
			buffer[3] == 0 && buffer[4] == 0)
		return (1);
	return (0);
}
