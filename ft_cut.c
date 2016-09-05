/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 01:33:19 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/05 02:32:11 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_cut(t_dlist *list, t_dlist *to_paste)
{
	char	*buffer;
	char	str[2];
	int		*tab2;
	int		index;

	index = 0;
	tab2 = malloc(sizeof(int) * ft_list_size(list->p_head));
	if (to_paste->length > 0)
		ft_delete_list(&to_paste);
	to_paste = NULL;
	to_paste = dlist_new(to_paste);
	to_paste->pos = 1;
	buffer = malloc(sizeof(char) * 7);
	while (42)
	{
		buffer = ft_bzero(buffer, 7);
		read(0, buffer, 6);
		if (ft_detect_right(buffer) == 1 && list->pos < list->length)
		{
			//	tputs(tgetstr("so", NULL), 0, ft_putchar2);
			// surligner le charactere actuel qu'on vient de rentrer dans la copy
			tab2[index] = list->pos + 1;
			index++;
			str[0] = ft_get_element_from_list(list, list->pos + 1)[0];
			str[1] = '\0';
			ft_add_data(to_paste, str);
			ft_right(list);
		}
		if (buffer[0] == 10)
		{
			index--;
			while (index >= 0)
			{
				ft_del_ele_list(list, tab2[index], list->p_head, 1);
				index--;
			}
			ft_move_begin();
			ft_clear_line();
			ft_display_list(list);
			free(buffer);
			free(tab2);
			return (list);
		}
	}
	free(tab2);
	free(buffer);
	return (list);
}
