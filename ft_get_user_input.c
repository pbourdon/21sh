/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:08:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/31 15:09:22 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_get_user_input(void)
{
	char		buffer[6];
	t_dlist		*list;

	list = NULL;
	list = dlist_new(list);
	while (42)
	{
		read(0, buffer, 6);
		ft_putstr(buffer);
		list = ft_deal_input(buffer, list);
	}
}
