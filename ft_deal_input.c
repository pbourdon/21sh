/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:11:20 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/31 16:20:58 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_deal_input(char *buffer, t_dlist *list)
{
	if (ft_detect_ctrl_d(buffer) == 1)
	{
		exit(EXIT_SUCCESS);
	}
	else if (ft_detect_right(buffer) == 1)
		return (ft_right(list));
	else if (ft_detect_left(buffer) == 1)
	{
		return (ft_left(list));
	}
	else if (ft_detect_up(buffer) == 1)
	{
		return (ft_up(list));
	}
	else if (ft_detect_down(buffer) == 1)
	{
		return (ft_down(list));
	}
	else
		return (ft_deal_input2(buffer, list));
}

t_dlist		*ft_deal_input2(char *buffer, t_dlist *list)
{
	if (buffer[0] == 127)
	{
		ft_putstr(" \nTHE LINE BEFORE DELETING : ");
		ft_display_list(list);
		ft_putstr(" \nTHE CURRENT POS IN THE LINE : ");
		ft_putnbr(list->pos);
		list = ft_del_ele_list(list, list->pos, list->p_head, 0);
		if (list->pos > 0)
		{
			list->pos = list->pos - 1;
		}
		ft_putstr(" \nTHE LINE AFTER DELETING : ");
		ft_display_list(list);
	}
//	if (ft_detect_end(buffer) == 1)
//	{
//	}
//	else if (ft_detect_swift_end(buffer) == 1)
//	{
//	}
//	else
//	{
	//	ft_putchar(buffer[0]);
	else
		list = ft_add_data(list, buffer);
//	}
	return (list);

}
