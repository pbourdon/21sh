/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:11:20 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/01 14:25:49 by pbourdon         ###   ########.fr       */
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
	char	test[2];
	if (buffer[0] == 127)
		return (ft_delete_on_shell(list));
	if (buffer[0] == 10)
	{
		ft_putchar('\n');
		ft_display_list(list);
		ft_delete_list(&list);
		list = NULL;
		list = dlist_new(list);
		return (list);
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
	{
		test[0] = buffer[0];
		test[1] = '\0';
		list = ft_add_element(list, test);
		return (list);
	}
//	}
	return (list);
}
