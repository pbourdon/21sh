/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 20:40:23 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/18 18:14:51 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_display_tab(char **arg)
{
	int		index;

	index = 0;
	while (arg[index] != 0)
	{
		ft_putstr(arg[index]);
		ft_putchar('\n');
		index++;
	}
}
