/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:19:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/20 15:14:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_run_unset(char *arg, t_dlist *list, t_dlist *histo)
{
	int		index;

	index = 0;
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\n')
	{
		index++;
	}
	if (arg[index] == '-' && arg[index + 1] == 'a')
	{
		ft_run_unsetenv(arg + index + 2, list);
	}
	else if (arg[index] == '-' && arg[index + 1] == 'f')
	{
		ft_run_unsetenv(ft_strjoin("function", arg + index + 2), list);
	}
	else
	{
		ft_run_unsetenv(arg + index, list);
	}
}
