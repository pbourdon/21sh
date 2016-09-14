/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_file_history.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:00:47 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/14 19:24:59 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_get_history_from_file(t_dlist *histo, int fd, int index, int index2)
{
	int		ret;
	char	buf[11];
	char	total[4096];

	if (fd == -1)
		return;
	while ((ret = read(fd, buf, 10)))
	{
		buf[ret] = '\0';
		while (buf[index2] != '\0')
		{
			total[index] = buf[index2];
			if (total[index] == '\n')
			{
				total[index] = '\0';
				index = 0;
				ft_add_data(histo, total);
			}
			else
				index++;
			index2++;
		}
		index2 = 0;
	}
	close(fd);
}