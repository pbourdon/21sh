/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_previous_histo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 20:23:00 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/05 01:31:24 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_previous_histo2(t_dlist *list, t_dlist *histo, char *str, int
index)
{
	char	str2[2];

	if (histo->pos > 1)
		histo->pos = histo->pos - 1;
	ft_move_begin();
	ft_clear_line();
	ft_delete_list(&list);
	list = NULL;
	list = dlist_new(list);
	str = ft_get_element_from_list(histo, histo->pos);
	while (str[index] != '\0')
	{
		str2[0] = str[index];
		str2[1] = '\0';
		list = ft_add_data(list, str2);
		index++;
	}
	ft_display_list(list);
	return (list);
}

t_dlist		*ft_previous_histo(t_dlist *list, t_dlist *histo)
{
	char	*str;

	str = ft_get_str_from_list(list);
	if (str != NULL)
		free(str);
	if (histo->pos > 0)
		return (ft_previous_histo2(list, histo, str, 0));
	return (list);
}
