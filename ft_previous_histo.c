/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_previous_histo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 20:23:00 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/04 22:11:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_previous_histo(t_dlist *list, t_dlist *histo)
{
	char	*str;
	int		index;
	char	str2[2];

	index = 0;
	if (histo->pos != 0)
	{
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
		ft_move_home(list);
		ft_left(list);
		ft_clear_n_char(600);
		ft_display_list(list);
		free(str);
		histo->pos = histo->pos - 1;
	}
	return (list);
}
