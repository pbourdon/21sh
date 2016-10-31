/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:05:54 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:05:56 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void	callecho(char **args)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		builtin_echo(args[i]);
		if (args[i + 1])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
