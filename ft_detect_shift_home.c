/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_shift_home.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:35:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 17:30:05 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_detect_shift_home(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 &&
		buf[3] == 59 && buf[4] == 50 && buf[5] == 72)
		return (1);
	return (0);
}
