/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:05:09 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:05:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void	cursor_init(void)
{
	g_cursor.position_x_abs = 1;
	g_cursor.position_y_abs = tgetnum("li") - 1;
	g_cursor.position_x_rel = 1;
	g_cursor.position_y_rel = 0;
	g_cursor.position_line = 0;
}
