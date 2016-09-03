/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:25:43 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 20:14:19 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_get_info_from_list(t_dlist *list)
{
	int		pos;
	char	*str;
	int		index;

	pos = 1;
	index = 0;
	str = ft_strnew(list->length);
	while (pos <= list->length)
	{
		str[index] = ft_get_element_from_list(list, pos)[0];
		index++;
		pos++;
	}
	if (ft_strcmp("exit", str) == 0)
		exit(EXIT_SUCCESS);
	// need to send the str to the correct programm and then free it
}
