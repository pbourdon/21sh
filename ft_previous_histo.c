/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_previous_histo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 20:23:00 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/07 15:50:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_previous_histo2(t_dlist *list, t_dlist *histo, char *str, int
index)
{
	char	str2[2];
	struct winsize sz;
	int		index2;
	char	*str3;
	int		index3;
	int		index4;

	index3 = 0;
	if (histo->pos > 1)
		histo->pos = histo->pos - 1;
	str3 = ft_get_element_from_list(histo, histo->pos);
//	ft_putchar('\n');
//	ft_putstr(str3);
	index2 = ft_strlen(str3);
	ioctl(0, TIOCGWINSZ, &sz);
	index2 = index2 / sz.ws_col;
	index4 = histo->index2;
	histo->index2 = index2;
	index2 = index4;
	ft_clear_line();
	while (index3 < index2)
	{
		ft_up(list);
		ft_clear_line();
		index3++;
	}
	ft_move_begin();
//	ft_putchar('\n');
//	ft_putstr(" the number of line of PREVIOUS DISPLAY is ");
//	ft_putnbr(index2);
//	ft_putchar('\n');
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
