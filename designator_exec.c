/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designator_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:05:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:05:28 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void			design_to_exec(t_data *data, t_liste2 *cur)
{
	int				i;
	t_history		*history;

	i = -1;
	history = g_shell.history;
	ft_putendl(history->str);
	create_command(history->str, cur);
	while (data->args && data->args[++i])
		ft_memdel((void **)&data->args[i]);
	ft_memdel((void **)&data->args);
	if (data->d == 0)
		built_or_launch(data);
	else
	{
		data->args = newtab(cur->tabb);
		execveremix(data, cur);
	}
}
