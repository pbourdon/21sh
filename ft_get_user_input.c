/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:08:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 17:00:56 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_get_user_input(void)
{
	char		*buffer;
	t_dlist		*list;

	list = NULL;
	buffer = malloc(sizeof(char) * 7);
	list = dlist_new(list);
	while (42)
	{
		buffer = ft_bzero(buffer, 7);
		read(0, buffer, 6);
		list = ft_deal_input(buffer, list);
	}
}
