/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclamation6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:52:25 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/19 18:55:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_exclamation6(char *arg, t_dlist *list, t_dlist *histo, int index)
{
	int		position;

	position = histo->length;
	while (position > 0)
	{
		if (ft_strncmp(ft_get_element_from_list(histo, position), arg, ft_strlen(arg)) == 0)
		{
			ft_putstr(ft_get_element_from_list(histo, position));
			ft_putchar('\n');
			ft_choose(ft_get_element_from_list(histo, position), list, histo);
			return;
		}
		position--;
		if (position == 0)
		{
			ft_putstr(" No event found\n");
			return;
		}
	}
	ft_putstr(" No event found\n");
	return;
}
