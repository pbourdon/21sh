/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclamation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:38:23 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/19 18:56:02 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_exclamation2(char *arg, t_dlist *list, t_dlist *histo, int index)
{
	ft_putstr(ft_get_element_from_list(histo, ft_atoi(arg) + 1));
	ft_putchar('\n');
	if (ft_strncmp(ft_get_element_from_list(histo, ft_atoi(arg) + 1), "!", 1)
	!= 0)
		ft_choose(ft_get_element_from_list(histo, ft_atoi(arg) + 1), list,
			histo);
	else
		ft_putstr("NICE TRY HAHA\n");
	return;
}

void		ft_exclamation3(char *arg, t_dlist *list, t_dlist *histo, int index)
{
	ft_putstr(ft_get_element_from_list(histo, histo->length - ft_atoi(arg + 1)));
	ft_putchar('\n');
	if (ft_strncmp(ft_get_element_from_list(histo, histo->length -
		ft_atoi(arg + 1)), "!", 1) != 0)
		ft_choose(ft_get_element_from_list(histo, histo->length - ft_atoi(arg + 1)),
		list, histo);
	else
		ft_putstr("NICE TRY HAHA\n");
	return;

}

void		ft_exclamation4(char *arg, t_dlist *list, t_dlist *histo, int index)
{
	ft_putstr(ft_get_element_from_list(histo, histo->length - 1));
	ft_putchar('\n');
	if (ft_strncmp(ft_get_element_from_list(histo, histo->length - 1), "!", 1)
		!= 0)
		ft_choose(ft_get_element_from_list(histo, histo->length - 1), list,
		histo);
	else
		ft_putstr("NICE TRY HAHA\n");
	return;
}

void		ft_exclamation5(char *arg, t_dlist *list, t_dlist *histo, int index)
{
	int		position;

	position = histo->length;
	while (position > 0)
	{
		if (ft_strstr(ft_get_element_from_list(histo, position), arg + index + 1) != NULL &&
			ft_strstr(ft_get_element_from_list(histo, position), "!?") == NULL)
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
}

void		ft_exclamation(char *arg, t_dlist *list, t_dlist *histo)
{
	int		index;

	index = 0;
	if (arg[index] == '\0')
	{
		// comprends pas son utilisation
		return;
	}
	if (arg[index] >= '0' && arg[index] <= '9')
		return (ft_exclamation2(arg, list, histo, index));
	if (arg[index] == '-' && arg[index + 1] >= '0' && arg[index + 1] <= '9')
		return (ft_exclamation3(arg, list, histo, index));
	if (arg[index] == '!')
		return (ft_exclamation4(arg, list, histo, index));
	if (arg[index] == '?')
		return (ft_exclamation5(arg, list, histo, index));
	return (ft_exclamation6(arg, list, histo, index));
}
