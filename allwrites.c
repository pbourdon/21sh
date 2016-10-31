/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allwrites.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:51:43 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 16:51:56 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void			writeonwhile(void)
{
	ft_putstr("minishell $> ");
}

void			errorbinary(t_data *data, char *str)
{
	if (str)
		ft_strdel(&str);
	ft_putstr("zsh: command not found: ");
	data->binreturn = 255;
	ft_putendl(data->args[0]);
}

t_liste2		*createliste(void)
{
	t_liste2	*liste;

	liste = (t_liste2 *)malloc(sizeof(t_liste2));
	liste->next = NULL;
	return (liste);
}
