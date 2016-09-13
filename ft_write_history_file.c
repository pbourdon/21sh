/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_history_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:57:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/13 17:39:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_write_history_file(t_dlist *histo)
{
	int		fd;
	int		pos;

	fd = open(".42sh_history", O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, S_IRUSR
 | S_IWUSR);
	pos = 1;
	while (pos < histo->length)
	{
		if (fd != -1)
		{
			ft_putstr_fd(ft_get_element_from_list(histo, pos), fd);
			ft_putchar_fd('\n', fd);
		}
		pos++;
	}
	ft_putstr_fd("history -a\n", fd);
	close(fd);

}
