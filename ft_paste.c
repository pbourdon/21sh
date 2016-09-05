/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 02:34:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/05 02:43:30 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_paste(t_dlist *list, t_dlist *to_paste)
{
	char	*str;
	int		index;
	char	str2[2];

	index = 0;
	str = ft_get_str_from_list(to_paste);
	ft_putstr(" the str to inser in the list is ");
	ft_putstr(str);
	while (str[index] != '\0')
	{
		str2[0] = str[index];
		str2[1] = '\0';
		list = ins_avant(list, str2, list->p_head ,list->pos + 1);
		index++;
	}
	if (to_paste->length > 0)
		ft_delete_list(&to_paste);
	ft_clear_line();
	ft_move_begin();
	ft_display_list(list);
	return (list);
}
