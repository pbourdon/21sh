/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_histo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 22:51:17 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/05 00:06:22 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_next_histo(t_dlist *list, t_dlist *histo)
{
	char	*str;
	int		index;
	char	str2[2];
	int		total;

	str = ft_get_str_from_list(list);
	total = ft_strlen(str);
	free(str);
	index = 0;
	if (histo->pos > 0 && histo->pos <= histo->length)
	{
		if (histo->pos < histo->length)
			histo->pos = histo->pos + 1;
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
	}
	return (list);
}
