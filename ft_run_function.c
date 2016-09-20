/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:44:47 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/20 14:28:14 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_run_function(char *arg, t_dlist *list, t_dlist *histo, int index)
{
	char	*tmp;
	int		pos;
	char	*buffer;

	ft_putstr("> ");
	buffer = malloc(sizeof(char) * 7);
	tmp = malloc(sizeof(char) * 4095);
	while (42)
	{
		buffer = ft_bzero(buffer, 7);
		read(0, buffer, 6);
		tmp[index] = buffer[0];
		ft_putchar(tmp[index]);
		index++;
		if (buffer[0] == 125 && buffer[1] == 0 && buffer[2] == 0 &&
			buffer[3] == 0 && buffer[4] == 0 && buffer[5] == 0)
		{
			tmp[index] = '\0';
			ft_add_data(list, ft_strjoin(arg, tmp));
			ft_putchar('\n');
			return;
		}
	}
}
