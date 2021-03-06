/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:07:41 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:07:43 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void	free_tabb(char **tabb)
{
	int i;

	i = -1;
	while (tabb[++i])
		ft_memdel((void **)&tabb[i]);
	free(tabb);
}

void	free_lfd(t_lfd *fd)
{
	t_lfd *tmp;

	while (fd)
	{
		tmp = fd->next;
		ft_memdel((void **)&fd);
		fd = tmp;
	}
}

void	free_lredir(t_lredi *redi)
{
	t_lredi	*tmp;

	while (redi)
	{
		tmp = redi->next;
		ft_memdel((void **)&redi->str);
		ft_memdel((void **)&redi);
		redi = tmp;
	}
}

void	free_all_liste(t_liste2 **l)
{
	t_liste2 *liste;
	t_liste2 *tmp;

	liste = *l;
	while (liste)
	{
		tmp = liste->next;
		free_tabb(liste->tabb);
		liste->tabb = NULL;
		free_lredir(liste->redir);
		liste->redir = NULL;
		free_lfd(liste->fd);
		liste->fd = NULL;
		ft_memdel((void **)&liste);
		liste = tmp;
	}
	l = NULL;
}
