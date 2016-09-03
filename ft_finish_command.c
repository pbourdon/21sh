/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:53:50 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 20:30:18 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_finish_command(t_dlist *list)
{
	ft_putchar('\n');
	ft_display_list(list);
	ft_get_info_from_list(list);
//	ft_run_commands(list);
	// need to handle how to keep in historic this list
	// to make tests, i free/recreate an empty list, but I need to modify that
	
	list = NULL;
	list = dlist_new(list);
	return (list);
}
