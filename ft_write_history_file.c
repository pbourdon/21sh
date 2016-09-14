/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_history_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:57:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/14 19:20:50 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_write_history_file(t_dlist *histo, int index, char *home)
{
	int		fd;
	int		pos;

	fd = open(home, O_RDWR | O_TRUNC | O_CREAT | O_APPEND, S_IRUSR
 | S_IWUSR);
	pos = 1;
//	ft_putstr(home);
//	ft_putchar('\n');
//	ft_putnbr(fd);
//	ft_putstr(" WRITING INTO THE FILE ");
	if (fd > 0)
	{
		while (pos < histo->length)
		{
		//	ft_putstr(ft_get_element_from_list(histo, pos));
		//	ft_putchar('\n');
			ft_putstr_fd(ft_get_element_from_list(histo, pos), fd);
			ft_putchar_fd('\n', fd);
			pos++;
		}
	}
	else
	{
		ft_putstr("An error just happened. Check your rights and home env variable");
		return;
	}
	if (index == 0)
		ft_putstr_fd("history -a\n", fd);
	else
		ft_putstr_fd("exit\n", fd);
	close(fd);

}
