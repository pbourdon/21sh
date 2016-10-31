/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cd_on_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:07:02 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:07:04 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void	exit_on_pipe(t_data *data, char **tabb)
{
	if (tabb[0] && tabb[1] && tabb[2])
		ft_putendl_fd("exit : too many arguments", 2);
	if (!tabb[1])
		exit((data->binreturn = 0));
	else if (tabb[0] && tabb[1])
	{
		if (ft_isnumber(tabb[1]) ||
			(tabb[1][0] == '-' && ft_isnumber(*(tabb + 1) + 1)))
			exit((data->binreturn = ft_atoi(tabb[1])));
		else
			ft_putendl_fd("exit: Expression Syntax.\n", 2);
	}
	exit((data->binreturn = 255));
}
