/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:14:14 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:14:16 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int		alreadyexist(char **tabb, char *str)
{
	int	i;

	i = 0;
	while (tabb[i])
	{
		if (rognagestring(str, tabb[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
