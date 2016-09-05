/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 01:33:19 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/05 02:17:19 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_copy(t_dlist *list, t_dlist *to_paste)
{
	char	*buffer;
	char	str[2];

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
			str[0] = ft_get_element_from_list(list, list->pos + 1)[0];
			str[1] = '\0';
			ft_add_data(to_paste, str);
			ft_right(list);
		}
		if (buffer[0] == 10)
		{
			ft_putstr(" \n the current copy is ");
			ft_display_list(to_paste);
			free(buffer);
			return (list);
		}
	}
	free(buffer);
	return (list);
}
