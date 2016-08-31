/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 17:42:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/31 17:48:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_add_element(t_dlist *list, char *buffer)
{
//	ft_putstr(" THE CURRENT POS IN LINE IS ");
//	ft_putnbr(list->pos);
//	ft_putstr(" \n THE CURRENT LENGTH OS THE LINE IS ");
//	ft_putnbr(list->length);
	ft_putchar(buffer[0]);
	if (list->pos == list->length)
		return (ft_add_data(list, buffer));
	else
	{
		return (ins_avant(list, buffer, list->p_head, list->pos));
	}
//	return (list);
}
