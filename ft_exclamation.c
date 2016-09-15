/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclamation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:38:23 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/15 19:17:04 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_exclamation(char *arg, t_dlist *list, t_dlist *histo)
{
	int		index;
	int		position;

	index = 0;
	if (arg[index] == '\0')
	{
		// comprends pas son utilisation
		return;
	}
	if (arg[index] >= '0' && arg[index] <= '9')
	{
		ft_putstr(ft_get_element_from_list(histo, ft_atoi(arg) + 1));
		ft_putchar('\n');
		if (ft_strncmp(ft_get_element_from_list(histo, ft_atoi(arg) + 1), "!", 1) != 0)
			ft_choose(ft_get_element_from_list(histo, ft_atoi(arg) + 1), list, histo);
		else
			ft_putstr("NICE TRY HAHA\n");
		return;
	}
	if (arg[index] == '-' && arg[index + 1] >= '0' && arg[index + 1] <= '9')
	{
		ft_putstr(ft_get_element_from_list(histo, histo->length - ft_atoi(arg + 1)));
		ft_putchar('\n');
		if (ft_strncmp(ft_get_element_from_list(histo, histo->length - ft_atoi(arg + 1)), "!", 1) != 0)
		ft_choose(ft_get_element_from_list(histo, histo->length - ft_atoi(arg + 1)), list, histo);
		else
			ft_putstr("NICE TRY HAHA\n");
		return;
	}
	if (arg[index] == '!')
	{
		ft_putstr(ft_get_element_from_list(histo, histo->length - 1));
		ft_putchar('\n');
		if (ft_strncmp(ft_get_element_from_list(histo, histo->length - 1), "!", 1) != 0)
			ft_choose(ft_get_element_from_list(histo, histo->length - 1), list, histo);
		else
			ft_putstr("NICE TRY HAHA\n");
		return;
	}
	if (arg[index] == '#')
	{
		// DONT KOWN
	}
	if (arg[index] == '?')
	{
		// dont know
	}
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
			ft_putstr("No event found\n");
	}

}
