/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_historic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 13:38:24 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 15:50:18 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_historic_after(t_dlist *list, t_dlist *histo)
{
	char		*str;
	int			index;
	char		str2[2];

	index = 0;
	if (histo->pos < histo->length)
		histo->pos = histo->pos + 1;
	if ((str = ft_get_element_from_list(histo, histo->pos)) != NULL)
	{
		while (str[index] != '\0')
		{
			str2[0] = str[index];
			str2[1] = '\0';
			ft_add_data(list, str2);
			index++;
		}
		ft_display_list(list);
		free(str);
	}
	return (0);
}

int		ft_historic_previous(t_dlist *list, t_dlist *histo)
{
	char		*str;
	int			index;
	char		str2[2];

	index = 0;
	if (histo->pos > 0)
		histo->pos = histo->pos - 1;
	if ((str = ft_get_element_from_list(histo, histo->pos)) != NULL)
	{
		while (str[index] != '\0')
		{
			str2[0] = str[index];
			str2[1] = '\0';
			ft_add_data(list, str2);
			index++;
		}
		ft_display_list(list);
		free(str);
	}
	return (0);
}
