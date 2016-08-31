/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_n_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:39:19 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/31 14:40:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_clear_n_char(int n)
{
	char	*res;

	if ((res = tgetstr("ec", NULL)) == NULL)
		return (-1);
	tputs(res, n, ft_putchar2);
	return (0);
}
