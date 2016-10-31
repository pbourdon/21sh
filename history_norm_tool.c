/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_norm_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:09:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:09:15 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

t_history		*hist_stock(char *line, t_history *n,
							t_history *p, t_history *history)
{
	history->str = ft_strdup(line);
	history->prev = p;
	history->next = n;
	return (history);
}
