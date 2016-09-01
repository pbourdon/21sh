/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 17:42:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/01 14:58:17 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_add_element(t_dlist *list, char *buffer)
{

/*	
	ft_putstr(" \n THE CURRENT POS IN LINE IS ");
	ft_putnbr(list->pos);
	ft_putstr(" \n THE CURRENT LENGTH OS THE LINE IS ");
	ft_putnbr(list->length);
	ft_putchar('\n');
	ft_putchar(' ');
//	ft_display_list(list);
//	*/
	
	if (list->pos == list->length)
	{
		ft_putchar(buffer[0]);
		return (ft_add_data(list, buffer));
	}
	else
	{
		tputs(tgetstr("im", NULL), 0, ft_putchar2);
		ft_putchar(buffer[0]);
		tputs(tgetstr("ei", NULL), 0, ft_putchar2);
//		if (list->pos == list->length + 1)
	//		return (ins_avant(list, buffer, list->p_head, list->pos - 1));
		return (ins_avant(list, buffer, list->p_head, list->pos + 1));
	}
//	return (list);
}
