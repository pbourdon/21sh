/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_previous_histo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 20:23:00 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/04 22:49:18 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_previous_histo(t_dlist *list, t_dlist *histo)
{
	char	*str;
	int		index;
	char	str2[2];
	int		total;

	total = ft_strlen(ft_get_str_from_list(list));
	index = 0;
	if (histo->pos != 0)
	{
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
		free(str);
		histo->pos = histo->pos - 1;
	}
	return (list);
}
