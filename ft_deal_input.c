/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:27:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/01 16:28:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_deal_input(char *buffer, t_dlist *list)
{
	if (ft_detect_ctrl_d(buffer) == 1)
		exit(EXIT_SUCCESS);
	else if (ft_detect_right(buffer) == 1)
		return (ft_right(list));
	else if (ft_detect_left(buffer) == 1)
		return (ft_left(list));
	else if (ft_detect_up(buffer) == 1)
	{
		// read the previous entry of historic
		return (ft_up(list));
	}
	else if (ft_detect_down(buffer) == 1)
	{
		// read the following entry of historic
		return (ft_down(list));
	}
	else
		return (ft_deal_input2(buffer, list));
}

t_dlist		*ft_deal_input2(char *buffer, t_dlist *list)
{
	if (buffer[0] == 127) // delete button
		return (ft_delete_on_shell(list));
	else if (buffer[0] == 10) // enter button
		return (ft_finish_command(list));
	else if (ft_detect_end(buffer) == 1)
		return (ft_move_end(list));
	else if (ft_detect_home(buffer) == 1)
		return (ft_move_home(list));
	else
		return (ft_add_element(list, buffer));
	return (list);
}
